#include "TextManager.h"
Font::Font(){
	width = 0;
	height = 0;
	font_texture_id = 0;
}
Font::Font(int textureid,int wth,int hgh,vector <SHP2Rectangle*> &letter,vector <unsigned int> &letter_id){
					  width = wth;
					  height = hgh;
					  font_texture_id = textureid;
                      letters = letter;
					  letter_ids = letter_id;
                    
           } 
int Font::getLetterRectangle(int id){
	unsigned int i = 0;
	if(letter_ids.size() > 0){
		while (i < letter_ids.size() && id != (int)letter_ids[i] ) i++;
		if(i < letter_ids.size()) return i;
	}
	return -1;
	
}
void TextManager::addText(SHP2Rectangle &pos,string text){
	positions.push_back(pos);
	texts.push_back(text);
}
void TextManager::BindFont(Font &tmf,Vector2 &sz){
	currentFont = tmf;
	size = sz;
}
void TextManager::cleanTexts(){
	positions.erase(positions.begin(),positions.end());
	texts.erase(texts.begin(),texts.end());
}
void TextManager::generateMesh(){
	MeshStore allDraw;
    SHP2Rectangle texRec,posRec;
	MeshStore tempMesh;
	for(unsigned int i = 0;i < positions.size();i++){
		posRec = positions[i];	
		
		posRec.vecMin.x += ( (posRec.vecMax.x - posRec.vecMin.x)-(size.x*strlen(texts[i].c_str())) )/2.0f;
		posRec.vecMin.y += ( (posRec.vecMax.y - posRec.vecMin.y)-(size.y))/2.0f;
		posRec.vecMax.y = posRec.vecMin.y + size.y;

		for(unsigned int j = 0;j < strlen(texts[i].c_str());j++){ 

			int num = currentFont.getLetterRectangle((unsigned int)texts[i][j]);//id of letter rectangle
			//num can be -1 this need if-else
			texRec.vecMin.change(
				1.0f/(float)currentFont.width * currentFont.letters[num]->vecMin.x,
				1.0f/(float)currentFont.height * currentFont.letters[num]->vecMin.y);
			texRec.vecMax.change(
				1.0f/(float)currentFont.width * currentFont.letters[num]->vecMax.x,
				1.0f/(float)currentFont.height * currentFont.letters[num]->vecMax.y
			);
			posRec.vecMax.changeX(posRec.vecMin.x + size.x);
			CreateMeshSHP2Rectangle(tempMesh,posRec,currentFont.font_texture_id,texRec); 
			allDraw.uniteMeshStore(tempMesh);	
			posRec.vecMin.x += size.x;
		
		}
	}
	
	if(text_mesh.isThereMesh())text_mesh.refreshMesh(allDraw);
	else text_mesh.createMesh(allDraw);
	
}
void TextManager::drawTexts(){
	glBindTexture(GL_TEXTURE_2D,currentFont.font_texture_id);
	text_mesh.drawMesh();
}



