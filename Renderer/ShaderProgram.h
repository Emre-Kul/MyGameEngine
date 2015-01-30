#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <fstream>
#include <string>
#include <iostream>
#include "GLEW\glew.h"
#include "../Math/Vectors.h"
#include "../Math/Matrix.h"
using namespace std;
class ShaderProgram{
	unsigned int programId,vertexShaderId,fragmentShaderId;
	
	void loadShaderFile(const char *filename,std::string &shader);
	unsigned int loadShader(std::string &source,unsigned int mode);
	
	public:
	//uniforms
	int transformationMatrix,projectionMatrix,viewMatrix;
	
	int vertexAtt,colorAtt,textureAtt,normalAtt;
	
	void initShader(const char* vsname,const char*fsname);
	
	void createAllAtt();
	void bindAllUniform();
	
	int getUniformLocation(std::string name){return glGetUniformLocation(programId,name.c_str());}//inline

	void loadVector(int location,Vector3 vec);
	void loadFloat(int location,float v);
	void loadBoolean(int location,bool bol);
	void loadMatrix(int location,Matrix4x4 &mtr);
	void loadInt(int location,int i);
		
	void startProgram();
	void stopProgram();

	int getProgramId(){return programId;}//inline

};

#endif