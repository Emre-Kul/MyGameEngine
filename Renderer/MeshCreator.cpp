#include "MeshCreator.h"

void CreateMeshSHP2Rectangle(MeshStore &meshStore,SHP2Rectangle &rec,int drawType){
	meshStore.setDrawType(drawType);
	meshStore.setTextureId(0);
	float VerCoords[12] = {
	rec.vecMin.x,rec.vecMin.y,0.0f,
	rec.vecMax.x,rec.vecMin.y,0.0f,
	rec.vecMax.x,rec.vecMax.y,0.0f,
	rec.vecMin.x,rec.vecMax.y,0.0f
	};
	unsigned int VerIndices[6] = {
	0,1,2,
	0,2,3
	};
	meshStore.setVertexCoords(VerCoords,12);
	meshStore.setIndexes(VerIndices,6);
}
void CreateMeshSHP2Rectangle(MeshStore &meshStore,SHP2Rectangle &rec,int drawType,float colorR,float colorG,float colorB){
	meshStore.setDrawType(drawType);
	meshStore.setTextureId(0);
	float VerCoords[12] = {
	rec.vecMin.x,rec.vecMin.y,0.0f,
	rec.vecMax.x,rec.vecMin.y,0.0f,
	rec.vecMax.x,rec.vecMax.y,0.0f,
	rec.vecMin.x,rec.vecMax.y,0.0f
	};
	float VerColor[12] = {
	colorR,colorG,colorB,
	colorR,colorG,colorB,
	colorR,colorG,colorB,
	colorR,colorG,colorB
	};
	unsigned int VerIndices[6] = {
	0,1,2,
	0,2,3
	};
	meshStore.setVertexCoords(VerCoords,12);
	meshStore.setColorCoords(VerColor,12);
	meshStore.setIndexes(VerIndices,6);
}
void CreateMeshSHP2Rectangle(MeshStore &meshStore,SHP2Rectangle &rec,int texture,SHP2Rectangle &textureRec){
	meshStore.setDrawType(DRAW_TYPE_POLYGON);
	meshStore.setTextureId(texture);
	float VerCoords[12] = {
		rec.vecMin.x,rec.vecMin.y,0.0f,
		rec.vecMax.x,rec.vecMin.y,0.0f,
		rec.vecMax.x,rec.vecMax.y,0.0f,
		rec.vecMin.x,rec.vecMax.y,0.0f
	};
	float TexCoords[8]={
		textureRec.vecMin.x,textureRec.vecMin.y,
		textureRec.vecMax.x,textureRec.vecMin.y,
		textureRec.vecMax.x,textureRec.vecMax.y,
		textureRec.vecMin.x,textureRec.vecMax.y
	};
	unsigned int VerIndices[6] = {
		0,1,2,
		0,2,3
	};
	meshStore.setVertexCoords(VerCoords,12);
	meshStore.setTextureCoords(TexCoords,8);
	meshStore.setIndexes(VerIndices,6);
}
