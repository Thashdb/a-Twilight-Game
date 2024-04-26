#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "shapes.h"
#include "colors.h"
#include <GL/gl.h>
#include <GL/glut.h>

struct Player {
    float posX;
    float posY;
    float velY;
    bool jumping;
    bool doubleJumping;

    // Construtor padrão
    Player() : posX(150.0f), posY(420.0f), velY(0.0f), jumping(false), doubleJumping(false) {}
};

const int MAX_ENEMIES = 50;

struct Enemies{
    float posX, posY;
    float velX;

    float initialSpeed = 3.0;
    float minDistance = 250.0;
    float maxdistance = 1000.0;

    float speed = initialSpeed;
};

void characFront(float x, float y);
void characSide(float x, float y);
void characDawn();

void tree(float x, float y);

#endif