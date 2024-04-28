#ifndef MOTION_H
#define MOTION_H

#include <iostream>
#include <vector>
using namespace std;


//inimigos
void enemiesMotion(int value);
void enemySpawn();
void enemyVel();

//jogador
void jump(int value);
bool checkCollision();

//chuva
struct RainDrop{
    float x=0.0;
    float y=0.0;
};

void rain(vector<RainDrop>& drops);
void raining(int value);

#endif