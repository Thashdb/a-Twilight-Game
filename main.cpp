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

Player player;
Enemies enemy[MAX_ENEMIES]; // vetor de inimigos

#pragma region score
int score=0;
int finalScore=0;
time_t startTime;
bool isTimerStarted = false;
#pragma endregion

//escolha de telas
bool start = true;
bool game = false;
bool endGame = false;

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

#pragma region reset 1

// void resetGame() {
//     // Reiniciar a posição dos inimigos
//     for (int i = 0; i < MAX_ENEMIES; ++i) {
//         // Defina a posição inicial dos inimigos conforme necessário
//         // Por exemplo:
//         enemy[i].posX = 1210;
//         enemy[i].posY = 480;
//         enemy[i].velX = enemy->initialSpeed;
//     }

//     // Zerar a pontuação
//     score = 0;

//     // Reiniciar o tempo de início
//     startTime = time(NULL);

//     // Definir o estado do jogo
//     game = true;
//     start = false;
//     endGame = false;
// }

#pragma endregion

// Função para desenhar os quadrados
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    if(start){ // inicia menu
        drawInit();
    }else if(game){  // teste inicial jogo
        start=endGame=false;
        drawGame();
    }else if(endGame){
        game=start=false;
        drawGameOver();
    }
    glFlush();
}

// Função para lidar com o teclado
void keyboard(unsigned char key, int x, int y) {
    //pulo
    if(game || start){
        if(key==32){
            if (!player.jumping) {
                player.jumping = true;
                player.velY = -8.0f; // Define a velocidade inicial do pulo
            }else if(player.jumping && !player.doubleJumping){
                player.doubleJumping= true;
                player.velY = -5.0f;
            }
        }
    }
    //start
    if(start){
        if(key==83 || key==115){    //S ou s para começar
            if (!isTimerStarted) {
                startTime = time(NULL); // Registra o tempo atual
                isTimerStarted = true; // Define a flag de temporizador iniciado como verdadeira
            }
            game = true;
            start = false;
        }
    }
    //restart
    else if(endGame){
        if(key==82 || 114){     // R ou r para recomeçar
            //resetGame();
            // Definir o estado do jogo
            game = true;
            start = false;
            endGame = false;

            // Zerar
            score = 0;
            startTime = time(NULL);
            enemy->speed = 3.0;         //era: speed = initialSpeed
            isTimerStarted = true; // Define a flag de temporizador iniciado como verdadeira
            glutKeyboardFunc(keyboard);
            enemyVel();
            draw();

        }  
    }
    // close
    if(key==27){    //esc
        exit(0);
    }
}


int main(int argc, char *argv[]) {
    // Inicializa o GLUT e configura a janela
    initGlut(argc, argv);
    setup();

    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    enemyVel();

    // Define as funções de callback e inicia o loop principal do GLUT
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, jump, 0);
    glutTimerFunc(5, enemiesMotion, 0);
    glutMainLoop();

    return 0;
}
