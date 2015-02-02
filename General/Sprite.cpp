#include "Sprite.h"
void FrameGroup::next(){
	if(currentFrameIndex >= frameOrder.size())
		currentFrameIndex = 0;
	else 
		currentFrameIndex++;
}
void FrameGroup::setFrameOrder(int *indexes,int indSize){
	frameOrder.clear();
	for(int i = 0;i < indSize;i++)
		frameOrder.push_back(indexes[i]);	
}
void FrameGroup::setFrameOrder(int index){
	frameOrder.clear();
	frameOrder.push_back(index);
}
Sprite::Sprite(){
	frameIndex = 0;
	groupId = 0;
}
void Sprite::draw(){
	glBindTexture(GL_TEXTURE_2D,textureResource->textureid);
	spritemesh.drawMesh();
}
void Sprite::generateMesh(SHP2Rectangle &position){	
	SHP2Rectangle tempTex;
	MeshStore temp;

	int width = textureResource->width;
	int height = textureResource->height;
	
	tempTex.vecMin.x = 1.0f/(float)width * frames[frameIndex]->vecMin.x;
	tempTex.vecMin.y = 1.0f/(float)height * frames[frameIndex]->vecMin.y;
	tempTex.vecMax.x = 1.0f/(float)width * frames[frameIndex]->vecMax.x;
	tempTex.vecMax.y = 1.0f/(float)height * frames[frameIndex]->vecMax.y;
	
	CreateMeshSHP2Rectangle(temp,position,textureResource->textureid,tempTex);
	
	if(!spritemesh.isThereMesh())spritemesh.createMesh(temp);
	else spritemesh.refreshMesh(temp);
}

void Sprite::setFrame(SHP2Rectangle& frame){
	frames.clear();
	frames.push_back(new SHP2Rectangle(frame));
}
void Sprite::setFrames(vector <SHP2Rectangle*> &slides){
     frames.clear();
     for(unsigned int i = 0;i < slides.size();i++) frames.push_back(slides[i]);
     }
void Sprite::setFrameGroup(FrameGroup &fgroups){
	frameGroup.clear();
	frameGroup.push_back(&fgroups);
}
void Sprite::setFrameGroup(vector <FrameGroup*> fgroups){
	frameGroup.clear();
	frameGroup = fgroups;
}
void Sprite::nextFrame(){
	if(frameGroup.size() > 0){
		frameGroup[groupId]->next();
		frameIndex = frameGroup[groupId]->getCurrentFrameIndex();
	}
	else {
		if(frameIndex >= frames.size()-1)frameIndex = 0;
		else frameIndex++;
	}
}
