#ifndef SHAPES_H
#define SHAPES_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void drawCircle(float centerX, float centerY, float radius);
void drawLine(float size,int x1, int y1, int x2, int y2);
void drawLineLoop(float size, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

#endif