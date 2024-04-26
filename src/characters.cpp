#include "../include/characters.h"
#include "../include/shapes.h"
#include "../include/colors.h"

void characFront(float x, float y){
    #pragma region head 
    //cabelo
    glColor3f(colors[0].r, colors[0].g, colors[0].b);     //preto
    drawSquare(x, y, x+40, y, x+40, y+45, x, y+45);
    //cabeça
    glColor3f(colors[2].r, colors[2].g, colors[2].b);      //pele
    drawSquare(x+5, y+5, x+35, y+5, x+35, y+40, x+5, y+40);
        //pescoço
        drawSquare(x+15, y+40, x+25, y+40, x+25, y+45, x+15, y+45);
    //olho
    glColor3f(colors[3].r, colors[3].g, colors[3].b);
    drawSquare(x+10, y+20, x+15, y+20, x+15, y+25, x+10, y+25); //E
    drawSquare(x+25, y+20, x+30, y+20, x+30, y+25, x+25, y+25); //D
    //blush
    glColor3f(colors[4].r, colors[4].g, colors[4].b);
    drawSquare(x+5, y+25, x+10, y+25, x+10, y+30, x+5, y+30);
    drawSquare(x+30, y+25, x+35, y+25, x+35, y+30, x+30, y+30);
    //detalhe cabelo
    glColor3f(colors[0].r, colors[0].g, colors[0].b);
    drawSquare(x+5, y+5, x+10, y+5, x+10, y+10, x+5, y+10);//E
    drawSquare(x+30, y+5, x+35, y+5, x+35, y+10, x+30, y+10);//D
#pragma endregion

#pragma region body 
    //blusa
    glColor3f(colors[5].r, colors[5].g, colors[5].b);
    drawSquare(x+5, y+45, x+35, y+45, x+35, y+75, x+5, y+75);
    //perna
    glColor3f(colors[0].r, colors[0].g, colors[0].b);
    drawSquare(x+5, y+75, x+35, y+75, x+35, y+85, x+5, y+85);
    drawSquare(x+5, y+85, x+15, y+85, x+15, y+105, x+5, y+105);//E
    drawSquare(x+25, y+85, x+35, y+85, x+35, y+105, x+25, y+105);//D
    // braço
    glColor3f(colors[2].r, colors[2].g, colors[2].b);      //pele
    drawSquare(x, y+50, x+5, y+50, x+5, y+70, x, y+70); //E
    drawSquare(x+35, y+50, x+40, y+50, x+40, y+70, x+35, y+70); //D
#pragma endregion

}

void characSide(float x, float y){
    #pragma region head 
    //cabeça
    glColor3f(colors[2].r, colors[2].g, colors[2].b);      //pele
    drawSquare(x+10, y+5, x+40, y+5, x+40, y+40, x+10, y+40);
        //pescoço
        drawSquare(x+20, y+40, x+25, y+40, x+25, y+45, x+20, y+45);
    //cabelo
    glColor3f(colors[0].r, colors[0].g, colors[0].b);     //preto
    drawSquare(x, y, x+40, y, x+40, y+5, x, y+5);
    drawSquare(x, y+5, x+15, y+5, x+15, y+10, x, y+10);
    drawSquare(x, y+10, x+10, y+10, x+10, y+45, x, y+45);
    drawSquare(x+10, y+35, x+15, y+35, x+15, y+45, x+10, y+45);
    drawSquare(x+15, y+40, x+20, y+40, x+20, y+45, x+15, y+45);
    
    //olho
    glColor3f(colors[3].r, colors[3].g, colors[3].b);
    drawSquare(x+30, y+20, x+35, y+20, x+35, y+25, x+30, y+25); //E
    //blush
    glColor3f(colors[4].r, colors[4].g, colors[4].b);
    drawSquare(x+25, y+25, x+30, y+25, x+30, y+30, x+25, y+30);
#pragma endregion

#pragma region body 
    //blusa
    glColor3f(colors[5].r, colors[5].g, colors[5].b);
    drawSquare(x+5, y+45, x+35, y+45, x+35, y+75, x+5, y+75);
    //perna
    glColor3f(colors[0].r, colors[0].g, colors[0].b);
    drawSquare(x+15, y+75, x+25, y+75, x+25, y+105, x+15, y+105);
    // braço
    glColor3f(colors[2].r, colors[2].g, colors[2].b);      //pele
    drawSquare(x+15, y+50, x+25, y+50, x+25, y+70, x+15, y+70); //E
#pragma endregion

}


void tree(float x, float y);