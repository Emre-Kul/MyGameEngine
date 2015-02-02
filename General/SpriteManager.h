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
	int activeSprite;
public:
	SpriteManager(){}

	void createSprite(std::string name);
	void bindSprite(std::string name);
	void bindSprite(int i){activeSprite = i;}
	
	Sprite& getSprite(std::string name);
	Sprite& getSprite(){return spriteResource[activeSprite].sprite;}
	bool searchSprite(std::string name,Sprite &spr);

};


#endif