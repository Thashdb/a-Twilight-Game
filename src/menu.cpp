#include "../include/menu.h"

MenuItem menuItems[] = {
    {100.0f, 100.0f, 200.0f, 50.0f, "Item 1"},
    {100.0f, 200.0f, 200.0f, 50.0f, "Item 2"},
    {100.0f, 300.0f, 200.0f, 50.0f, "Item 3"}
};

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
    drawText(280, 80, "A");

}