#ifndef COLORS_H
#define COLORS_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

struct Color {
    GLfloat r, g, b;
};

extern std::vector<Color> colors;

#endif
