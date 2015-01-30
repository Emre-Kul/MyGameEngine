#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include <iostream>
#include "../Renderer/MeshCreator.h"
#include "../Physics/Shapes2D.h"
#include "TextureManager.h"

using namespace std;

class FrameGroup{
	vector <int> frameOrder;//{0,1,1,0}
	int currentFrameIndex;//2
public:
	
	void setFrameOrder(int *indexes,int indSize);
	void setFrameOrder(int index);
	void next();
	int getCurrentFrameIndex(){return frameOrder[currentFrameIndex];}
};
class Sprite{
	int groupId,frameIndex;
	vector <FrameGroup*> frameGroup;
	vector <SHP2Rectangle*> frames;
	
	TextureResource *textureResource;
	Mesh spritemesh;
	
public:
	Sprite();

	void setFrame(SHP2Rectangle &frame);
    void setFrames(vector <SHP2Rectangle*> &frame);
	void setFrameGroup(FrameGroup &fgroups);
	void setFrameGroup(vector <FrameGroup*> fgroups);
	
	void nextFrame();
	void generateMesh(SHP2Rectangle &position);
	
	void draw();
		//inlines//
	void setTextureResource(TextureResource &tr){textureResource = &tr;}
	TextureResource& getTextureResource(){return *textureResource;}

};

#endif
