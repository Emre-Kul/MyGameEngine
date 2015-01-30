#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "Sprite.h"

struct SpriteResource{
	std::string spriteName;
	Sprite sprite;
	SpriteResource(Sprite spr,std::string name);
};
class SpriteManager{
	std::vector <SpriteResource> spriteResource;

public:
	
	void addSprite(Sprite sprite,std::string name);
	Sprite& getSprite(std::string name);
	bool searchSprite(std::string name,Sprite &spr);

};


#endif