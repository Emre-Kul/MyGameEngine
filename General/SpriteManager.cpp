#include "SpriteManager.h"
SpriteResource::SpriteResource(Sprite spr,std::string name){
	sprite = spr;
	spriteName = name;
}



void SpriteManager::createSprite(std::string name){

	spriteResource.push_back(SpriteResource(Sprite(),name));
	bindSprite(spriteResource.size()-1);

}
void SpriteManager::bindSprite(std::string name){
	unsigned i = 0;
	if(spriteResource.size() > 0){
		while (i < spriteResource.size() && strcmp(spriteResource[i].spriteName.c_str(),name.c_str()) ) i++;
		if(i < spriteResource.size()) bindSprite(i);
	}
}
Sprite& SpriteManager::getSprite(std::string name){
	unsigned int i = 0;
	if(spriteResource.size() > 0){	
		while (i < spriteResource.size() && strcmp(spriteResource[i].spriteName.c_str(),name.c_str()) ) i++;
		if(i < spriteResource.size()) return spriteResource[i].sprite;
	}
	return Sprite();
}
bool SpriteManager::searchSprite(std::string name,Sprite &spr){
	unsigned int i = 0;
	if(spriteResource.size() > 0){
		while (i < spriteResource.size() && !strcmp(spriteResource[i].spriteName.c_str(),name.c_str()) ) i++;
		if(i < spriteResource.size()) {
			spr = spriteResource[i].sprite;
			return true;
		}
	}
	return false;
}