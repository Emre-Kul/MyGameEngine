#include "Game.h"
void Game::gameInit(){
	srand((unsigned int)time(NULL));//for boost and floor generation
	prepareShaders();
}
void Game::refresh(){

}
void Game::render(){
	
}
void Game::update(){
	
}	
		//privates
void Game::prepareShaders(){
	textureShaderProgram.initShader("Data/Shaders/vertex.vs","Data/Shaders/fragment.fs");
	textureShaderProgram.bindAllUniform();
	textureShaderProgram.createAllAtt();
	glActiveTexture(GL_TEXTURE0);
	textureShaderProgram.loadInt(textureShaderProgram.getUniformLocation("textureSampler"),0);	
}