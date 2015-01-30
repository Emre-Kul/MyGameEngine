#ifndef BASICDRAWER2D_H
#define BASICDRAWER2D_H

#include <Windows.h>
#include <gl\GL.h>
#include "../Physics/Shapes2D.h"

const int DRAW_POINT = 0;
const int DRAW_LINE = 1;
const int DRAW_POLYGON = 2;

void DrawSHP2Rectangle(SHP2Rectangle &rec,int drawType);
void DrawSHP2Rectangle(SHP2Rectangle &rec,int texture,SHP2Rectangle &textureRec);
void DrawSHP2Rectangle(SHP2Rectangle &rec,int texture,SHP2Rectangle &textureRec,int direction);

void DrawSHP2Triangle(SHP2Triangle &tri,int drawType);
void DrawSHP2Ray(SHP2Ray &ray);

#endif