#include "ShaderProgram.h"
void ShaderProgram::loadShaderFile(const char *filename,std::string &shader){
	std::ifstream in(filename);
	if(!in.is_open()){
	printf("Shader File Cant Open");
	return;
	}
	char tmp[256];
	while (!in.eof())
	{
		in.getline(tmp,256);
		shader += tmp;
		shader += '\n';
	}
}
unsigned int ShaderProgram::loadShader(std::string &source,unsigned int mode){
	unsigned int id;
	id = glCreateShader(mode);
	const char* csource = source.c_str();
	glShaderSource(id,1,&csource,NULL);
	glCompileShader(id);
	//no error control
	return id;
}
void ShaderProgram::initShader(const char* vsname,const char*fsname){
std::string source;
loadShaderFile(vsname,source);
vertexShaderId = loadShader(source,GL_VERTEX_SHADER);
source = "";
loadShaderFile(fsname,source);
fragmentShaderId = loadShader(source,GL_FRAGMENT_SHADER);
programId = glCreateProgramObjectARB();
glAttachShader(programId,vertexShaderId);
glAttachShader(programId,fragmentShaderId);
glLinkProgram(programId);
}
void ShaderProgram::loadVector(int location,Vector3 vec){
	glUniform3f(location,vec.x,vec.y,vec.z);
}
void ShaderProgram::loadFloat(int location,float v){
	glUniform1f(location,v);
}
void ShaderProgram::loadBoolean(int location,bool bol){
float t = 0;
if(bol) t = 1;
glUniform1f(location,t);
}
void ShaderProgram::loadMatrix(int location,Matrix4x4 &mtr){
	float *value = mtr.getMatrix();
	glUniformMatrix4fv(location,1,false,value);
}
void ShaderProgram::loadInt(int location,int i){
	glUniform1i(location,i);
}
void ShaderProgram::startProgram(){
	glUseProgram(programId);
}
void ShaderProgram::stopProgram(){
	glUseProgram(0);
}
void ShaderProgram::createAllAtt(){
	glBindAttribLocation(programId,0,"position");vertexAtt = 0;
	glBindAttribLocation(programId,1,"textureCoords");textureAtt = 1;
	glBindAttribLocation(programId,2,"color");colorAtt = 2;
}
void ShaderProgram::bindAllUniform(){
	projectionMatrix = getUniformLocation("projectionMatrix");
	viewMatrix = getUniformLocation("viewMatrix");
	transformationMatrix = getUniformLocation("transformationMatrix");
}