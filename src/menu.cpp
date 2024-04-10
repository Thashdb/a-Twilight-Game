#include "../include/menu.h"

void drawText(float posX, float posY, const char *string){
    glRasterPos2f(posX, posY); //posicao inicial do texto
    //percorre string
    for(int i=0; string[i]!='\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }

}

