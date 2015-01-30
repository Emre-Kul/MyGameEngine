#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct TextureResource{
	//int hash_id;//emin deðilim nasýl yapacaðým ama þimdilik dursun burda
	int textureid,width,height;
	string name;
	TextureResource(int id,string nm,int wd,int hg);
};

class TextureManager{
	vector <TextureResource> textures;	
  public:
	 
	  void addTexture(int textureid,string name,int width,int height);
	  TextureResource& getTexture(string name);
	  bool searchTexture(string name,int &id);

};//need hashtable
#endif