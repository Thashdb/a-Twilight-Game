#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/shapes.h"
#include "include/screens.h"

//tela
int SCREEN_WIDTH, SCREEN_HEIGHT;
int width = 1200, height = 580;
//score
char text[50], aux[20];
int score=0;
int finalScore=0;
time_t startTime;
bool isTimerStarted = false;

//escolha de telas
bool start = true;
bool game = false;
bool endGame = false;

#pragma region enimies
// Estrutura para representar os quadrados pretos
struct BlackSquare {
    float posX;
    float posY;
    float velX;
};
// Constantes para o número máximo de quadrados pretos e a velocidade
const int MAX_BLACK_SQUARES = 50;
const float BLACK_SQUARE_SPEED = 3.0f;

const float MIN_DISTANCE = 200.0f;


// Array para armazenar os quadrados pretos
BlackSquare blackSquares[MAX_BLACK_SQUARES];
#pragma endregion

#pragma region player
// Variáveis para o jogador
float playerPosX = 150.0f, playerPosY = 420.0f;
float playerVelY = 0.0f;
bool jumping = false;
#pragma endregion

#pragma region inicialização
// Função de inicialização do GLUT
void initGlut(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    SCREEN_WIDTH = glutGet(GLUT_SCREEN_WIDTH);
    SCREEN_HEIGHT = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
    glutCreateWindow("a Twilight Game");
}
// Função de configuração do OpenGL
void setup() {
    glClearColor(0.29f, 0.36f, 0.29f, 1.0f); // Cor de fundo (verdinho)
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, width, height, 0);
}
#pragma endregion

// Função para desenhar os quadrados
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    if(start){ // inicia menu
        drawInit();
    }else if(game){  // teste inicial jogo
        start=endGame=false;
        glColor3f(1.0f, 1.0f, 1.0f); // Cor branca para o jogador

        // Desenha o jogador
        drawSquare(playerPosX, playerPosY, 
                playerPosX + 60, playerPosY, 
                playerPosX + 60, playerPosY + 120, 
                playerPosX, playerPosY + 120);
        //imprime pontuação
        strcpy(text, "Score: ");
        sprintf(aux, "%d", score*5);    //multiplicador de pontos
        strcat(text, aux);
        drawTextH1(880, 50, text);

        // Desenha os quadrados pretos
        glColor3f(0.0f, 0.0f, 0.0f); // Cor preta para os quadrados pretos
        for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {
            drawSquare(blackSquares[i].posX, blackSquares[i].posY,
                    blackSquares[i].posX + 50, blackSquares[i].posY,
                    blackSquares[i].posX + 50, blackSquares[i].posY + 50,
                    blackSquares[i].posX, blackSquares[i].posY + 50);
        }
    }else if(endGame){
        game=start=false;
        drawTextH1(500, 250, "Game Over");
        char finalScoreText[50];
        sprintf(finalScoreText, "Final Score: %d", finalScore);
        drawTextH1(500, 300, finalScoreText);
    }
    glFlush();
}

// Função para verificar a colisão AABB
bool checkCollision() {
    // Verifica se houve colisão entre o jogador e os quadrados pretos
    for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {
        if (playerPosX + 60 >= blackSquares[i].posX && blackSquares[i].posX + 50 >= playerPosX && playerPosY + 120 >= blackSquares[i].posY && playerPosY <= blackSquares[i].posY + 50) {
            return true;
        }
    }
    return false;
}

// Função para mover os quadrados pretos
void motion(int values) {
    // Move os quadrados pretos para a esquerda até sair da tela
    for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {
        if (blackSquares[i].posX > -100) {
            blackSquares[i].posX -= blackSquares[i].velX;
        }
    }

    // Verifica a colisão a cada movimento
    if (checkCollision()) {
        finalScore = score*5;
        printf("Bateu\n");
        game=false;
        endGame=true;
    }
    glutTimerFunc(16, motion, 0);
    glutPostRedisplay();
}

// Função para lidar com o teclado
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 32: // Barra de espaço
            if (!jumping) {
                jumping = true;
                playerVelY = -8.0f; // Define a velocidade inicial do pulo
            }
            break;
        case 83: // S
        case 115: // s
            if (!isTimerStarted) {
                startTime = time(NULL); // Registra o tempo atual
                isTimerStarted = true; // Define a flag de temporizador iniciado como verdadeira
            }
            game = true;
            start = false;
            break;
        case 82: // R
        case 114: // r
            endGame = true;
            game = false;
            score = 0;
            break;
        case 27: // Esc
            exit(0);
            break;
    }
}

// Função para atualizar o pulo do jogador
void update(int value) {
    if (jumping) {
        playerVelY += 0.2f; // Aumenta a velocidade no eixo y (simula a gravidade)
        playerPosY += playerVelY; // Atualiza a posição no eixo y

        // Quando o jogador atinge o solo, redefine a posição e a velocidade
        if (playerPosY >= 420.0f) {
            playerPosY = 420.0f;
            playerVelY = 0.0f;
            jumping = false;
        }
    }
        if (isTimerStarted && game) { // Se o temporizador foi iniciado e o jogo está em execução
        // Calcule o tempo decorrido desde o início em segundos
        time_t currentTime = time(NULL);
        double elapsedTime = difftime(currentTime, startTime);

        // Atualiza o score com base no tempo decorrido
        score = elapsedTime;

        // Aqui você pode adicionar outras lógicas de atualização do jogo com base no tempo
    }

    glutTimerFunc(16, update, 0); // Chama a função de atualização novamente após 16ms
    glutPostRedisplay(); // Solicita uma nova renderização
}

int main(int argc, char *argv[]) {
    // Inicializa o GLUT e configura a janela
    initGlut(argc, argv);
    setup();

    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    // // Inicializa a posição e a velocidade dos quadrados pretos
    // for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {
    //     blackSquares[i].posX = 1210.0f + rand() % 1000;
    //     blackSquares[i].posY = 480.0f + rand() % 50;
    //     blackSquares[i].velX = BLACK_SQUARE_SPEED;
    // }

//mod

    // Inicializa a posição e a velocidade dos quadrados pretos
    for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {

        if (i == 0){
            blackSquares[i].posX = 1210.0f + rand() % 1000;
            blackSquares[i].posY = 480.0f + rand() % 50;
            blackSquares[i].velX = BLACK_SQUARE_SPEED;
        }
        else{
            // Gera uma nova posição aleatória
            float newPosX, newPosY;
            bool validPosition;

            do {
                newPosX = blackSquares[i-1].posX + rand() % 1000;
                newPosY = 480.0f + rand() % 50;

                // Define a posição como válida inicialmente
                validPosition = true;

                // Verifica se a nova posição viola a distância mínima em relação aos quadrados existentes
                if (fabs(newPosX - blackSquares[i-1].posX) < MIN_DISTANCE) {
                    // Se a distância mínima for violada, a posição não é válida
                    validPosition = false;
                }

            } while (!validPosition); // Repete o processo até encontrar uma posição válida

            // Atribui a posição válida ao quadrado preto
            blackSquares[i].posX = newPosX;
            blackSquares[i].posY = newPosY;
            blackSquares[i].velX = BLACK_SQUARE_SPEED;
        }

    }


//mod

    // Define as funções de callback e inicia o loop principal do GLUT
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutTimerFunc(5, motion, 0);
    glutMainLoop();

    return 0;
}
