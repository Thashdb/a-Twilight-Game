#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/shapes.h"
#include "include/screens.h"
#include "include/characters.h"
#include "include/motion.h"

//tela
int SCREEN_WIDTH, SCREEN_HEIGHT;
int width = 1200, height = 580;

Enemies enemies; // Instância da estrutura Enemies
Player player;

//escolha de telas
bool start = true;
bool game = false;
bool endGame = false;

#pragma region score
    int score=0;
    int finalScore=0;
    time_t startTime;
    bool isTimerStarted = false;
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

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    if(start){ // inicia menu
        drawInit();
    }else if(game){  // teste inicial jogo
        start=endGame=false;
        score=0; 
        enemyVel();
        finalScore=drawGame(score);
        glutTimerFunc(20, enemiesMotion, 0);
        
    }else if(endGame){
        game=start=false;
        drawTextH1(500, 250, "Game Over");
        char finalScoreText[50];
        sprintf(finalScoreText, "Final Score: %d", finalScore);
        drawTextH1(500, 300, finalScoreText);
        glutTimerFunc(16, raining, 0);
    }
    glFlush();
}

// Função para lidar com o teclado
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 32: // Barra de espaço
            if (!player.jumping) {
                player.jumping = true;
                player.velY = -5.0f; // Define a velocidade inicial do pulo
            }else if(player.jumping && !player.doubleJumping){
                player.doubleJumping= true;
                player.velY = -5.0f;
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
        case 82: // R-estart
        case 114: // r
            endGame = false;
            game = true;
            score = 0;
            break;
        case 27: // Esc
            exit(0);
            break;
    }
}

int main(int argc, char *argv[]) {
    // Inicializa o GLUT e configura a janela
    initGlut(argc, argv);
    setup();

    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));
    
    // Define as funções de callback e inicia o loop principal do GLUT
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, jump, 0);
    glutMainLoop();

    return 0;
}
