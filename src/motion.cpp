#include "../include/motion.h"
#include "../include/characters.h"

#include <time.h>

extern Player player;
extern Enemies enemy[MAX_ENEMIES];
//extern RainDrop raindrops; // Declarando raindrops como uma variável global
extern vector<RainDrop> raindrops;

extern int score, finalScore;
extern time_t startTime;
extern bool isTimerStarted;

extern bool game, endGame;

extern int width, height;

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
        // Calcula o tempo decorrido desde o início em segundos
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
    for (int i = 0; i < MAX_ENEMIES; ++i) {
        if (player.posX + 40 >= enemy[i].posX && enemy[i].posX + 50 >= player.posX && player.posY + 105 >= enemy[i].posY && player.posY <= enemy[i].posY + 50) {
            return true;
        }
    }
    return false;
}

#pragma region enemies velocity

void enemyVel(){
    // Inicializa a posição e a velocidade dos quadrados pretos
    for (int i = 0; i < MAX_ENEMIES; ++i) {

        if (i == 0){
            enemy[i].posX = 1210.0f + rand() % 1000;
            enemy[i].posY = 480.0f + rand() % 25;       // se não quiser mudanças no eixo y tira (+ rand() % 50)
            enemy[i].velX = enemy->speed;
        }
        else{
            // Gera uma nova posição aleatória
            float newPosX, newPosY;
            bool validPosition;

            do {
                newPosX = enemy[i-1].posX + rand() % 1000; 
                newPosY = 480.0f + rand() % 25;           // se não quiser mudanças no eixo y tira (+ rand() % 50)

                // Define a posição como válida inicialmente
                validPosition = true;

                // Verifica se a nova posição viola a distância mínima em relação aos quadrados existentes
                if ((fabs(newPosX - enemy[i-1].posX) < enemy->minDistance) || (fabs(newPosX - enemy[i-1].posX) > enemy->maxdistance)) {
                    // Se a distância mínima for violada, a posição não é válida
                    validPosition = false;
                }

            } while (!validPosition); // Repete o processo até encontrar uma posição válida

            enemy->speed += 0.1f;
            // Atribui a posição válida ao quadrado preto
            enemy[i].posX = newPosX;
            enemy[i].posY = newPosY;
            enemy[i].velX = enemy->speed;
        }

    }
}

#pragma endregion

// Função para mover os quadrados pretos
void enemiesMotion(int values) {
    // Move os quadrados pretos para a esquerda até sair da tela
    for (int i = 0; i < MAX_ENEMIES; ++i) {
        if (enemy[i].posX > -100) {
            enemy[i].posX -= enemy[i].velX;
        }
    }

    // Verifica a colisão a cada movimento
    if (checkCollision()) {
        finalScore = score+1;       // era: score*5
        printf("Bateu\n");
        game=false;
        endGame=true;
    }
    glutTimerFunc(16, enemiesMotion, 0);
    glutPostRedisplay();
}

void rain(std::vector<RainDrop>& drops) {
    glColor3f(0.61f, 0.84f, 1.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (const auto& drop : drops) {
        glVertex2f(drop.x, drop.y);
        glVertex2f(drop.x, drop.y - 10); // Desenha a gota de chuva como uma linha vertical
    }
    glEnd();
}

void raining(int value) {
    for (auto& drop : raindrops) {
        drop.x += static_cast<float>(rand() % 5) - 2.5f; 
        drop.y += static_cast<float>(rand() % 5); 
        if (drop.y > height-50) {
            drop.y = 0; //reinicia a posição no topo da tela
            drop.x = static_cast<float>(rand() % width); //reinicia a posição x
        }
    }
    glutPostRedisplay(); // Redesenha a cena
    glutTimerFunc(16, raining, 0);
}



