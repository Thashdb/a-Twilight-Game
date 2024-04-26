#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "shapes.h"
#include "colors.h"
#include <GL/gl.h>
#include <GL/glut.h>


struct Enemies {
    int nMax = 50; // Número máximo de quadrados pretos
    float MIN_DISTANCE = 250.0f; // Distância mínima entre os quadrados pretos
    float MAX_DISTANCE = 1000.0f; // Distância máxima entre os quadrados pretos
    float initialSpeed = 3.0f;

    float speed=initialSpeed;

    struct BlackSquare {
        float posX;
        float posY;
        float velX;
    };
    
    BlackSquare blackSquares[50]; // Aqui você pode definir o tamanho diretamente como 50
};


struct Player {
    float posX;
    float posY;
    float velY;
    bool jumping;
    bool doubleJumping;

    // Construtor padrão
    Player() : posX(150.0f), posY(420.0f), velY(0.0f), jumping(false), doubleJumping(false) {}
};

void characFront(float x, float y);
void characSide(float x, float y);

void tree(float x, float y);

#endif