#include "TextureManager.h"

TextureResource::TextureResource(int id,string nm,int wd,int hg){
textureid = id;
name = nm;
width = wd;
height = hg;
}



void TextureManager::addTexture(int textureid,string name,int width,int height){
	textures.push_back(TextureResource(textureid,name,width,height));
}
TextureResource& TextureManager::getTexture(string name){
	int i = 0;
	if(textures.size() > 0){
	while (i < textures.size() && strcmp(textures[i].name.c_str(),name.c_str()) ) i++;
	if(i < textures.size()) return textures[i];
	}
	return textures[0];

}//control et yanlýþ olabilir ve çok dandik bir fonksiyon yavaþ ve kullanýþsýz ama idare eder
bool TextureManager::searchTexture(string name,int &id){
	int i = 0;
	if(textures.size() > 0){
		while (i < textures.size() && !strcmp(textures[i].name.c_str(),name.c_str()) ) i++;
		if(i < textures.size()) {
			id = textures[i].textureid;
			return true;
		}
	}
	return false;
}


