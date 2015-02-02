#include "BasicDrawer2D.h"
void DrawSHP2Rectangle(SHP2Rectangle &rec,int drawType){
	if(drawType == DRAW_LINE) {
	glBegin(GL_LINE_STRIP);
	glVertex2f(rec.vecMin.x,rec.vecMin.y);
	glVertex2f(rec.vecMax.x,rec.vecMin.y);
	glVertex2f(rec.vecMax.x,rec.vecMax.y); 
	glVertex2f(rec.vecMin.x,rec.vecMax.y);
	glVertex2f(rec.vecMin.x,rec.vecMin.y);
	glEnd();
	}
	else if(drawType == DRAW_POINT) {
	glBegin(GL_POINTS);
	glVertex2f(rec.vecMin.x,rec.vecMin.y);
	glVertex2f(rec.vecMax.x,rec.vecMin.y);
	glVertex2f(rec.vecMax.x,rec.vecMax.y);
	glVertex2f(rec.vecMin.x,rec.vecMax.y);
	glEnd();
	}
	else {
	glBegin(GL_POLYGON);
	glVertex2f(rec.vecMin.x,rec.vecMin.y);
	glVertex2f(rec.vecMax.x,rec.vecMin.y);
	glVertex2f(rec.vecMax.x,rec.vecMax.y);
	glVertex2f(rec.vecMin.x,rec.vecMax.y);
	glEnd();
	}
	
}
void DrawSHP2Rectangle(SHP2Rectangle &rec,int texture,SHP2Rectangle &tRec){
	glBindTexture(GL_TEXTURE_2D,texture);
	glBegin(GL_POLYGON);
	glTexCoord2f(tRec.vecMin.x,tRec.vecMin.y);glVertex2f(rec.vecMin.x,rec.vecMin.y);
	glTexCoord2f(tRec.vecMax.x,tRec.vecMin.y);glVertex2f(rec.vecMax.x,rec.vecMin.y);
	glTexCoord2f(tRec.vecMax.x,tRec.vecMax.y);glVertex2f(rec.vecMax.x,rec.vecMax.y);
	glTexCoord2f(tRec.vecMin.x,tRec.vecMax.y);glVertex2f(rec.vecMin.x,rec.vecMax.y);
	glEnd();
}
void DrawSHP2Rectangle(SHP2Rectangle &rec,int texture,SHP2Rectangle &tRec,int direction){
	glBindTexture(GL_TEXTURE_2D,texture);
	if(direction == -1){
	glBegin(GL_POLYGON);
	glTexCoord2f(tRec.vecMax.x,tRec.vecMin.y);glVertex2f(rec.vecMin.x,rec.vecMin.y);
	glTexCoord2f(tRec.vecMin.x,tRec.vecMin.y);glVertex2f(rec.vecMax.x,rec.vecMin.y);
	glTexCoord2f(tRec.vecMin.x,tRec.vecMax.y);glVertex2f(rec.vecMax.x,rec.vecMax.y);
	glTexCoord2f(tRec.vecMax.x,tRec.vecMax.y);glVertex2f(rec.vecMin.x,rec.vecMax.y);
	glEnd();
	}
	else{
	glBegin(GL_POLYGON);
	glTexCoord2f(tRec.vecMin.x,tRec.vecMin.y);glVertex2f(rec.vecMin.x,rec.vecMin.y);
	glTexCoord2f(tRec.vecMax.x,tRec.vecMin.y);glVertex2f(rec.vecMax.x,rec.vecMin.y);
	glTexCoord2f(tRec.vecMax.x,tRec.vecMax.y);glVertex2f(rec.vecMax.x,rec.vecMax.y);
	glTexCoord2f(tRec.vecMin.x,tRec.vecMax.y);glVertex2f(rec.vecMin.x,rec.vecMax.y);
	glEnd();
	
	}
}
void DrawSHP2Triangle(SHP2Triangle &tri,int drawType){}
void DrawSHP2Ray(SHP2Ray &ray){

	glBegin(GL_LINES);
	glVertex2f(ray.P0.x,ray.P0.y);
	glVertex2f(ray.P1.x,ray.P1.y);
	glEnd();
}

void DrawSHP2Circle(SHP2Circle &circ,int drawType){
	float x,y;
	glPointSize(2);
    glBegin(GL_POINTS);
    for(float i = 0;i < 360;i++){
           x = cos(i);
           y = sin(i);
		   glVertex3f(x*circ.r + circ.center.x,y*circ.r + circ.center.y,0);
       }
	glEnd();
	
}

