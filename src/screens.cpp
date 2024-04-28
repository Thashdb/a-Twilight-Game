#include "../include/screens.h"
#include "../include/shapes.h"
#include "../include/characters.h"
#include "../include/motion.h"

#include <string.h>

extern int width, height;
char text[50], aux[20];
extern int score;
extern int finalScore;

extern Player player;
extern Enemies enemy[MAX_ENEMIES];


void drawTextH1(float posX, float posY, const char *string){
    glRasterPos2f(posX, posY); //posicao inicial do texto
    //percorre string
    for(int i=0; string[i]!='\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}

void drawTextH2(float posX, float posY, const char *string){
    glRasterPos2f(posX, posY); //posicao inicial do texto
    //percorre string
    for(int i=0; string[i]!='\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

void draw(MenuItem *items, int itemCount){
    for(int i=0; i<itemCount; i++){
        MenuItem item = items[i];
        drawTextH1(item.x, item.y, item.text);
        glColor3f(0, 0, 0);
        drawLineLoop(1, item.x, item.y, item.x+item.width, item.y, item.x+item.width, item.y+item.height, item.x, item.y+item.height);
    }
}

void drawInit(){
    //tela de menu
    glClearColor(0.7f, 0.74f, 0.6f, 1.0f); // Cor de fundo (verdinho)
    characFront(player.posX, player.posY);
    glColor3f(0, 0, 0);
    drawTextH1(width/2.1, 80, "A");
    drawTextH1(width/2.4, 120, "Twilight Game");
    drawTextH2(width/2.35, height/1.2, "press S to start");
}

void drawGame(){
    // Desenha o jogador
        characSide(player.posX, player.posY);
        //imprime pontuação
        glColor3f(1.0f, 1.0f, 1.0f); // Cor branca para o jogador
        strcpy(text, "Score: ");
        sprintf(aux, "%d", score+1);    //multiplicador de pontos, era: score*5
        strcat(text, aux);
        drawTextH1(880, 50, text);

        // Desenha os quadrados pretos
        glColor3f(0.0f, 0.0f, 0.0f); // Cor preta para os quadrados pretos
        for (int i = 0; i < MAX_ENEMIES; ++i) {
            drawSquare(enemy[i].posX, enemy[i].posY,
                    enemy[i].posX + 50, enemy[i].posY,
                    enemy[i].posX + 50, enemy[i].posY + 50,
                    enemy[i].posX, enemy[i].posY + 50);
        }
}

void drawGameOver(vector<RainDrop>& raindrops) {
    // Desenha o texto "Game Over" e a pontuação final
    glColor3f(0.0f, 0.0f, 0.0f);
    drawTextH1(500, 250, "Game Over");
    char finalScoreText[50];
    sprintf(finalScoreText, "Final Score: %d", finalScore);
    drawTextH1(500, 300, finalScoreText);
    drawTextH2(500, 500, "press R to restart");

    // Desenha a chuva na tela
    rain(raindrops);
    raining(0);
    
    // Desenha o personagem caído
    characDawn();

}
