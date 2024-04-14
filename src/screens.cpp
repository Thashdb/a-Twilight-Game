#include "../include/screens.h"
#include "../include/shapes.h"

extern int width, height;
extern float playerPosX, playerPosY;

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
    glColor3f(0, 0, 0);
    drawSquare(playerPosX, playerPosY, 
                playerPosX + 60, playerPosY, 
                playerPosX + 60, playerPosY + 120, 
                playerPosX, playerPosY + 120);
    drawTextH1(width/2.1, 80, "A");
    drawTextH1(width/2.4, 120, "Twilight Game");
    drawTextH2(width/2.35, height/1.2, "press S to start");
}