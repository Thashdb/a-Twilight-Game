#include <GL/gl.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/shapes.h"

int SCREEN_WIDTH, SCREEN_HEIGHT;
int width = 1200, height = 580;

// Estrutura para representar os quadrados pretos
struct BlackSquare {
    float posX;
    float posY;
    float velX;
};

// Constantes para o número máximo de quadrados pretos e a velocidade
const int MAX_BLACK_SQUARES = 10;
const float BLACK_SQUARE_SPEED = 3.0f;

// Array para armazenar os quadrados pretos
BlackSquare blackSquares[MAX_BLACK_SQUARES];

// Variáveis para o jogador
float playerPosX = 150.0f;
float playerPosY = 490.0f;
float playerVelY = 0.0f;
bool jumping = false;

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
    glClearColor(0.29f, 0.56f, 0.29f, 1.0f); // Cor de fundo (verdinho)
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, width, height, 0);
}

// Função para desenhar os quadrados
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // Cor branca para o jogador

    // Desenha o jogador
    drawSquare(playerPosX, playerPosY, 
               playerPosX + 30, playerPosY, 
               playerPosX + 30, playerPosY + 40, 
               playerPosX, playerPosY + 40);

    // Desenha os quadrados pretos
    glColor3f(0.0f, 0.0f, 0.0f); // Cor preta para os quadrados pretos
    for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {
        drawSquare(blackSquares[i].posX, blackSquares[i].posY,
                   blackSquares[i].posX + 50, blackSquares[i].posY,
                   blackSquares[i].posX + 50, blackSquares[i].posY + 50,
                   blackSquares[i].posX, blackSquares[i].posY + 50);
    }

    glFlush();
}

// Função para verificar a colisão AABB
bool checkCollision() {
    // Verifica se houve colisão entre o jogador e os quadrados pretos
    for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {
        if (playerPosX + 30 >= blackSquares[i].posX && blackSquares[i].posX + 50 >= playerPosX && playerPosY + 40 >= blackSquares[i].posY && playerPosY <= blackSquares[i].posY + 50) {
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
        printf("Bateu\n");
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
        if (playerPosY >= 500.0f) {
            playerPosY = 500.0f;
            playerVelY = 0.0f;
            jumping = false;
        }
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

    // Inicializa a posição e a velocidade dos quadrados pretos
    for (int i = 0; i < MAX_BLACK_SQUARES; ++i) {
        blackSquares[i].posX = 1210.0f + rand() % 1000;
        blackSquares[i].posY = 480.0f + rand() % 50;
        blackSquares[i].velX = BLACK_SQUARE_SPEED;
    }

    // Define as funções de callback e inicia o loop principal do GLUT
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutTimerFunc(5, motion, 0);
    glutMainLoop();

    return 0;
}
