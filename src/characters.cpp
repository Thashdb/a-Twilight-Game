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

void characDawn(){
    float x = 150, y = 485;

    #pragma region head 
        //cabeça
        glColor3f(colors[2].r, colors[2].g, colors[2].b);      //pele
        drawSquare(x+65, y, x+100, y, x+100, y+30, x+65, y+30);
            //pescoço
            drawSquare(x+60, y+15, x+65, y+15, x+65, y+20, x+60, y+20);
        //cabelo
        glColor3f(colors[0].r, colors[0].g, colors[0].b);     //preto
        drawSquare(x+100, y, x+105, y, x+105, y+40, x+100, y+40);
        drawSquare(x+95, y+25, x+100, y+25, x+100, y+40, x+95, y+40);
        drawSquare(x+60, y+20, x+65, y+20, x+65, y+40, x+60, y+40);
        drawSquare(x+65, y+25, x+70, y+25, x+70, y+40, x+65, y+40);
        drawSquare(x+70, y+30, x+95, y+30, x+95, y+40, x+70, y+40);
        
        //olho
        glColor3f(colors[0].r, colors[0].g, colors[0].b);
        drawLine(3, x+85, y+5, x+90, y+10);
        drawLine(3, x+90, y+5, x+85, y+10);
        //glColor3f(colors[3].r, colors[3].g, colors[3].b);
        //drawSquare(x+85, y+5, x+90, y+5, x+90, y+10, x+85, y+10); //E
        //blush
        glColor3f(colors[4].r, colors[4].g, colors[4].b);
        drawSquare(x+80, y+10, x+85, y+10, x+85, y+15, x+80, y+15);
    #pragma endregion

    #pragma region body 
        //blusa
        glColor3f(colors[5].r, colors[5].g, colors[5].b);
        drawSquare(x+30, y+5, x+60, y+5, x+60, y+35, x+30, y+35);
        //perna
        glColor3f(colors[0].r, colors[0].g, colors[0].b);
        drawSquare(x, y+15, x+30, y+15, x+30, y+25, x+0, y+25);
        // braço
        glColor3f(colors[2].r, colors[2].g, colors[2].b);      //pele
        drawSquare(x+35, y+15, x+55, y+15, x+55, y+25, x+35, y+25); //E
    #pragma endregion
}

void drawTree(int size, float x, float y, int aux1, int aux2, int aux3){
    glColor3f(colors[aux1].r, colors[aux1].g, colors[aux1].b);
    drawSquare(x+(6*size), y, x+(12*size), y, x+(12*size), y+(5*size), x+(6*size), y+(5*size));
    drawSquare(x+(4*size), y+(5*size), x+(14*size), y+(5*size), x+(14*size), y+(11*size), x+(4*size), y+(11*size));
    drawSquare(x, y+(11*size), x+(18*size), y+(11*size), x+(18*size), y+(17*size), x, y+(17*size));
    glColor3f(colors[aux3].r, colors[aux3].g, colors[aux3].b);
    drawSquare(x+(7*size), y+(17*size), x+(11*size), y+(17*size), x+(11*size), y+(21*size), x+(7*size), y+(21*size));
}

void drawGround(int size, float x, float y, int aux1, int aux2, int aux3){
    
}