#include "../include/screens.h"
#include "../include/shapes.h"
#include "../include/characters.h"
#include "../include/motion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int width, height;
extern int score;

char text[50], aux[20];

extern Enemies enemies; // Instância da estrutura Enemies
extern Player player;

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


int drawGame(int score) {
    characSide(player.posX, player.posY); // Desenha o jogador

    // Desenha a pontuação
    glColor3f(1.0f, 1.0f, 1.0f); // Cor branca
    sprintf(text, "Score: %d", score * 5); // Cria a string formatada com a pontuação
    drawTextH1(880, 50, text); // Desenha o texto na tela

    // Desenha os quadrados pretos
    enemySpawn();

    return score; // Retorna a pontuação multiplicada por 5
}