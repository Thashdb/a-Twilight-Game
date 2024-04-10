#include "../include/shapes.h"

const int numSegments = 100; // Número de segmentos para aproximar o círculo


void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    glBegin(GL_TRIANGLES);
        glVertex2d(x1, y1);     
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
    glEnd();
}

void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    glBegin(GL_QUADS);
        glVertex2d(x1, y1);     //primerio vertice
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
        glVertex2d(x4, y4);
    glEnd();
}

void drawCircle(float centerX, float centerY, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Centro do círculo

    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.1415926f * float(i) / float(numSegments); // Ângulo para cada segmento
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);

        glVertex2f(centerX + x, centerY + y);
    }

    glEnd();
}

void drawLine(float size, int x1, int y1, int x2, int y2){
    glLineWidth(size);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void drawLineLoop(float size, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    glLineWidth(size);
    glBegin(GL_LINE_LOOP);
        glVertex2d(x1, y1);     
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
        glVertex2d(x4, y4);
    glEnd();
}