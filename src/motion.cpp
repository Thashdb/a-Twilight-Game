#include <iostream>
#include <vector>
using namespace std;

#include "../include/motion.h"
#include "../include/characters.h"

extern Player player;
extern Enemies enemies;

extern bool game, endGame;

extern int score, finalScore;
extern bool isTimerStarted;
extern time_t startTime;

extern int width, height;
vector<RainDrop> raindrops(500);    //vetor para armazenar chuva

void enemiesMotion(int value){
    // Move os quadrados pretos para a esquerda até sair da tela
    for (int i = 0; i < enemies.nMax; ++i) {
        if (enemies.blackSquares[i].posX > -100) {
            enemies.blackSquares[i].posX -= enemies.blackSquares[i].velX;
        }
    }

     // Verifica a colisão a cada movimento
    if (checkCollision()) {
        finalScore = score*5;
        printf("Bateu\n");
        game=false;
        endGame=true;
    }
    glutTimerFunc(16, enemiesMotion, 0);
    glutPostRedisplay();
}

void enemySpawn(){
    glColor3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i < enemies.nMax; ++i) {
        drawSquare(enemies.blackSquares[i].posX, enemies.blackSquares[i].posY,
                   enemies.blackSquares[i].posX + 50, enemies.blackSquares[i].posY,
                   enemies.blackSquares[i].posX + 50, enemies.blackSquares[i].posY + 50,
                   enemies.blackSquares[i].posX, enemies.blackSquares[i].posY + 50);
    }
}

void enemyVel(){
    /// Inicializa a posição e a velocidade dos quadrados pretos
    for (int i = 0; i < enemies.nMax; ++i) {
        if (i == 0) {
            enemies.blackSquares[i].posX = 1210.0f + rand() % 1000;
            enemies.blackSquares[i].posY = 480.0f + rand() % 50;
            enemies.blackSquares[i].velX = enemies.speed;
        } else {
            // Gera uma nova posição aleatória
            float newPosX, newPosY;
            bool validPosition;
            do {
                newPosX = enemies.blackSquares[i - 1].posX + rand() % 1000;
                newPosY = 480.0f + rand() % 50;
                // Define a posição como válida inicialmente
                validPosition = true;
                // Verifica se a nova posição viola a distância mínima em relação aos quadrados existentes
                if ((fabs(newPosX - enemies.blackSquares[i - 1].posX) < enemies.MIN_DISTANCE) || (fabs(newPosX - enemies.blackSquares[i - 1].posX) > enemies.MAX_DISTANCE)) {
                    // Se a distância mínima for violada, a posição não é válida
                    validPosition = false;
                }
            } while (!validPosition); // Repete o processo até encontrar uma posição válida
            enemies.speed += 0.01f;
            // Atribui a posição válida ao quadrado preto
            enemies.blackSquares[i].posX = newPosX;
            enemies.blackSquares[i].posY = newPosY;
            enemies.blackSquares[i].velX = enemies.speed;
        }
    }
}

void jump(int value) {
    if (player.jumping) {
        player.velY += 0.2f; // Aumenta a velocidade no eixo y (simula a gravidade)
        player.posY += player.velY; // Atualiza a posição no eixo y

        // Quando o jogador atinge o solo, redefine a posição e a velocidade
        if (player.posY >= 420.0f) { // A condição deve ser >=, não apenas >
            player.posY = 420.0f;
            player.velY = 0.0f;
            player.jumping = false;
            player.doubleJumping = false;
        }
    }
    if (isTimerStarted && game) { // Se o temporizador foi iniciado e o jogo está em execução
        // Calcule o tempo decorrido desde o início em segundos
        time_t currentTime = time(NULL);
        double elapsedTime = difftime(currentTime, startTime);

        // Atualiza o score com base no tempo decorrido
        score = elapsedTime;
    }

    glutTimerFunc(16, jump, 0); // Chama a função de atualização novamente após 16ms
    glutPostRedisplay(); // Solicita uma nova renderização
}

// Função para verificar a colisão AABB
bool checkCollision() {
    // Verifica se houve colisão entre o jogador e os quadrados pretos
    for (int i = 0; i < enemies.nMax; ++i) {
        if (player.posX + 40 >= enemies.blackSquares[i].posX && enemies.blackSquares[i].posX + 50 >= player.posX && player.posY + 105 >= enemies.blackSquares[i].posY && player.posY <= enemies.blackSquares[i].posY + 50) {
            return true;
        }
    }
    return false;
}

void rain(std::vector<RainDrop>& drops){
    glColor3f(0.61f, 0.84f, 1.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for(const auto& drop : drops){
        glVertex2f(drop.x, drop.y);
        glVertex2f(drop.x, drop.y-10);
    }
    glEnd();
}

void raining(int value){
    for (auto& drop : raindrops) {
        drop.y += 1.0; // Move a gota de chuva para baixo
        if (drop.y > height) {
            drop.y = 0; // Se a gota de chuva atingir a parte inferior da tela, reinicie na parte superior
            drop.x = rand() % width; // Reinicie a posição x aleatoriamente
        }
    }
    glutPostRedisplay(); // Redesenha a cena
    glutTimerFunc(16, raining, 0);
}
