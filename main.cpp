#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>

#include "include/shapes.h"
#include "include/screens.h"
#include "include/characters.h"
#include "include/motion.h"
using namespace std;

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
string playerName = "";

#pragma endregion

//escolha de telas
bool start = true;
bool game = false;
bool endGame = false;

vector<RainDrop> raindrops(500);

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

void saveScore(const string& playerName, int score) {
    ofstream file("score.txt", ios::app); // Abrir o arquivo no modo de anexação
    if (file.is_open()) {
        file << "Player: " << playerName;
        file << "\t Score: " << score << endl;
        file.close();
        cout << "Score saved successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

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
        //drawRain();
        drawGameOver(raindrops);
    }
    glFlush();
}

// Função para lidar com o teclado
void keyboard(unsigned char key, int x, int y) {
    // Pulo
    if(game || start){
        if(key == 32){
            if (!player.jumping) {
                player.jumping = true;
                player.velY = -8.0f; // Define a velocidade inicial do pulo
            }else if(player.jumping && !player.doubleJumping){
                player.doubleJumping= true;
                player.velY = -5.0f;
            }
        }
    }
    // Start
    if(start){
        if(key == 49){    // Tecla 1 para começar
            if (!isTimerStarted) {
                startTime = time(NULL); // Registra o tempo atual
                isTimerStarted = true; // Define a flag de temporizador iniciado como verdadeira
            }
            game = true;
            start = false;
        }
    }
    // Restart
    else if(endGame){
        if(isalpha(key) || key == 32){
            if(playerName.size() < 20) { // Limita o tamanho máximo do nome do jogador
                playerName += key; // Adiciona o caractere digitado ao nome do jogador
            }
        }
        // Se a tecla pressionada for o backspace (para apagar letras)
        else if(key == 8 && !playerName.empty()){
            playerName.pop_back(); // Remove o último caractere do nome do jogador
        }
        if(key == 13) { // Se a tecla Enter for pressionada
            // Salva a pontuação com o nome do jogador
            saveScore(playerName, finalScore);
        }
        if(key == 50){     // Tecla 2 para recomeçar
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
    // Close
    if(key == 27){    // Tecla Esc para sair
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
