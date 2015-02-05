#ifndef MESH_H
#define MESH_H
#ifndef GL_UNSIGNED_SHORT_5_6_5
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#endif
#ifndef GL_CLAMP_TO_EDGE 
#define GL_CLAMP_TO_EDGE 0x812F
#endif 

#include <vector> 
#include <iostream>
#include <Windows.h>
#include "GLEW/GLew.h"
#include "ShaderProgram.h"

using namespace std;

const int DRAW_TYPE_POLYGON = 0;
const int DRAW_TYPE_POINT = 1;
const int DRAW_TYPE_LINE = 2;

struct VAO{
	GLuint VERTEXVBO,COLORVBO,TEXTUREVBO,NORMALVBO,INDEXVBO,texture_id;
	int VertexSize;
	VAO();

};
class MeshStore{
       int textureId,drawType;
	   
	   vector <float> vertexCoord;
	   vector <float> normalCoord;
	   vector <float> colorCoord;
	   vector <float> textureCoord;
	   vector <unsigned int> indexes;
	   
public:
	   
	   int colorVBOindex,vertexVBOindex,normalVBOindex,textureVBOindex,indexesVBOindex,VBOindex;
       
	   MeshStore();
	   void setVertexCoords(float *vt,int size);
	   void setNormalCoords(float *vt,int size);
	   void setColorCoords(float *vt,int size);
	   void setTextureCoords(float *vt,int size);
	   void setIndexes(unsigned int *vt,int size);

	   vector <float>& getVertexCoord(){return vertexCoord;}
	   vector <float>& getNormalCoord(){return normalCoord;}
	   vector <float>& getColorCoord(){return colorCoord;}
	   vector <float>& getTextureCoord(){return textureCoord;}
	   vector <unsigned int>& getIndexes(){return indexes;}

	   void setTextureId(int Id){textureId = Id;}//inline
	   void setDrawType(int type){drawType = type;}//inline
	  
	   int getTextureId(){return textureId;}//inline
	   int setDrawType(){return drawType;}//inline
		
	   void uniteMeshStore(MeshStore ms);

};
class Mesh{
		VAO VAOID;
	public:
		
		void createMesh(MeshStore &ms);//it create multible vbo
		void refreshMesh(MeshStore &ms);
		void releaseMesh();
		void drawMesh();
		bool isThereMesh();

}; 

#endif
 
