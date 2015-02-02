#include "Game.h"
void Game::initOpengl(){
	glewExperimental = GL_TRUE; 
	glewInit();
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
}

		//privates
void Game::prepareShaders(){
	textureShaderProgram.initShader("Data/Shaders/vertex.vs","Data/Shaders/fragment.fs");
	textureShaderProgram.bindAllUniform();
	textureShaderProgram.createAllAtt();
	glActiveTexture(GL_TEXTURE0);
	textureShaderProgram.loadInt(textureShaderProgram.getUniformLocation("textureSampler"),0);	
}