#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "shapes.h"
#include "colors.h"
#include <GL/gl.h>
#include <GL/glut.h>


#pragma region Player
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
    void characDawn();
#pragma endregion

#pragma region Enenies
const int MAX_ENEMIES = 100;

struct Enemies{
    float posX, posY;
    float velX;

    float initialSpeed = 3.0;
    float minDistance = 300.0;
    float maxdistance = 1000.0;

    float speed = initialSpeed;
};
#pragma endregion

#pragma region Trees
    struct Tree {
        float x;
        float y;
    };

    const int MAX_TREES = 30; 

    void drawTree(int size, float x, float y, int aux1, int aux2, int aux3);
#pragma endregion

#endif