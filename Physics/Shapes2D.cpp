#include "Shapes2D.h"
SHP2Rectangle::SHP2Rectangle(){}
SHP2Rectangle::SHP2Rectangle(float a,float b,float c,float d){
                        vecMin.change(a,b);
                        vecMax.change(c,d);
}

SHP2Circle::SHP2Circle(){r = 0;}
SHP2Circle::SHP2Circle(float cx,float cy,float radi){
                     center.change(cx,cy);
                     r = radi;
}
SHP2Circle::SHP2Circle(Vector2 &vec,float radi){
                       center.change(vec.x,vec.y);
                       r = radi;
}	

SHP2Ray::SHP2Ray(){}
SHP2Ray::SHP2Ray(float x0,float y0,float x1,float y1){
                  P0.change(x0,y0);
                  P1.change(x1,y1);
}
SHP2Ray::SHP2Ray(Vector2 &vec1,Vector2 &vec2){
                    P0.change(vec1.x,vec1.y);
                    P1.change(vec2.x,vec2.y);
}       
