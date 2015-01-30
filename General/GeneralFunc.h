#ifndef GENERALFUNC_H
#define GENERALFUNC_H

#include <fstream>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <GLEW\glew.h>
#include "../Physics/Shapes2D.h"


int loadTexture(const char *texName);
Vector2 calculateMouseCord(int scWitdh,int scHeight,int mx,int my,float firstx,float lastx,float firsty,float lasty);
SHP2Rectangle setToMid(SHP2Rectangle &rec);

#endif