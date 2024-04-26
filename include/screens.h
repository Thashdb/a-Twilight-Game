#ifndef MENU_H
#define MENU_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

#include "shapes.h"

struct MenuItem {
    float x, y; // Posição do texto
    float width, height; // Tamanho da área clicável
    const char *text; // Texto do item do menu
};

void drawTextH1(float posX, float posY, const char *string);
void drawInit();
int drawGame(int score);

#endif