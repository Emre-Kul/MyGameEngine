#include "GeneralFunc.h"
int loadTexture(const char *texName){
	 GLuint mTexture;
           mTexture = SOIL_load_OGL_texture(
					texName,
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_POWER_OF_TWO
					| SOIL_FLAG_MIPMAPS
					//| SOIL_FLAG_MULTIPLY_ALPHA
					//| SOIL_FLAG_COMPRESS_TO_DXT
					| SOIL_FLAG_DDS_LOAD_DIRECT
					//| SOIL_FLAG_NTSC_SAFE_RGB
					//| SOIL_FLAG_CoCg_Y
					//| SOIL_FLAG_TEXTURE_RECTANGLE
					);
    if(mTexture <= 0){
        printf("[Texture loader] \"%s\" failed to load!\n", texName);
        return 0;
        }


        glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT );
        return (int)mTexture;

}
Vector2 calculateMouseCord(int scWitdh,int scHeight,int mx,int my,float firstx,float lastx,float firsty,float lasty){
						 
                         Vector2 vec;
						 
                         if(scWitdh <= mx) mx = scWitdh -1;
                         else if (mx <= 0) mx = 1;
                         
                         if(scHeight <= my) my = scHeight -1;
                         else if (my <= 0) my = 1;
                         
                         float wtd = (float)scWitdh/(lastx - firstx);
                         float hgh = (float)scHeight/(lasty - firsty);
                        
						 vec.changeX( ((float)mx/wtd) + firstx);
						 if(firsty < 0)
                         vec.changeY(- firsty - ((float)my/hgh));
						 else
						 vec.changeY(firsty + ((float)my/hgh));
						 
						 return vec;
}
SHP2Rectangle setToMid(SHP2Rectangle &rec){
	SHP2Rectangle tempRec;
	Vector2 tempVec;
	
	float midx = (rec.vecMax.x + rec.vecMin.x)/2;
	float midy = (rec.vecMax.y + rec.vecMin.y)/2;
	tempVec.change(midx,midy);
	tempRec = rec;
	
	tempRec.vecMax -= tempVec;
	tempRec.vecMin -= tempVec;
	
	return tempRec;

}