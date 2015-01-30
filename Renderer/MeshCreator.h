#ifndef MESHCREATOR_H
#define MESHCREATOR_H

#include "Mesh.h"
#include "../Physics/Shapes2D.h"

void CreateMeshSHP2Rectangle(MeshStore &meshStore,SHP2Rectangle &rec,int drawType);
void CreateMeshSHP2Rectangle(MeshStore &meshStore,SHP2Rectangle &rec,int drawType,float colorR,float colorG,float colorB);
void CreateMeshSHP2Rectangle(MeshStore &meshStore,SHP2Rectangle &rec,int texture,SHP2Rectangle &textureRec);



#endif