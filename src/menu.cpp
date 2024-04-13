#include "../include/menu.h"
#include "../include/shapes.h"

extern int width, height;
extern float playerPosX, playerPosY;

void drawText(float posX, float posY, const char *string){
    glRasterPos2f(posX, posY); //posicao inicial do texto
    //percorre string
    for(int i=0; string[i]!='\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }

}

void draw(MenuItem *items, int itemCount){
    for(int i=0; i<itemCount; i++){
        MenuItem item = items[i];
        drawText(item.x, item.y, item.text);
        glColor3f(0, 0, 0);
        drawLineLoop(1, item.x, item.y, item.x+item.width, item.y, item.x+item.width, item.y+item.height, item.x, item.y+item.height);
    }
}

void drawMenu(){
    //tela de menu
    glClearColor(0.7f, 0.74f, 0.6f, 1.0f); // Cor de fundo (verdinho)
    glColor3f(0, 0, 0);
    drawSquare(playerPosX, playerPosY, 
                playerPosX + 30, playerPosY, 
                playerPosX + 30, playerPosY + 40, 
                playerPosX, playerPosY + 40);
    drawText(width/2.1, 80, "A");
    drawText(width/2.4, 120, "Twilight Game");
}