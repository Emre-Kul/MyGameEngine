#include "SpriteManager.h"
SpriteResource::SpriteResource(Sprite spr,std::string name){
	sprite = spr;
	spriteName = name;
}
void SpriteManager::addSprite(Sprite sprite,std::string name){
	spriteResource.push_back(SpriteResource(sprite,name));
}
Sprite& SpriteManager::getSprite(std::string name){
	int i = 0;
	if(spriteResource.size() > 0){
		while (i < spriteResource.size() && strcmp(spriteResource[i].spriteName.c_str(),name.c_str()) ) i++;
		if(i < spriteResource.size()) return spriteResource[i].sprite;
	}
	return Sprite();
}
bool SpriteManager::searchSprite(std::string name,Sprite &spr){
	int i = 0;
	if(spriteResource.size() > 0){
		while (i < spriteResource.size() && !strcmp(spriteResource[i].spriteName.c_str(),name.c_str()) ) i++;
		if(i < spriteResource.size()) {
			spr = spriteResource[i].sprite;
			return true;
		}
	}
	return false;
}