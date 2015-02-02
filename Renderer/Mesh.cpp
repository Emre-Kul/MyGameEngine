#include "mesh.h"
VAO::VAO(){
	VERTEXVBO = 0;
	COLORVBO = 0;
	TEXTUREVBO = 0;
	NORMALVBO = 0;
	INDEXVBO = 0;
	VertexSize = 0;
	}
MeshStore::MeshStore(){
   	colorVBOindex = -1;
	vertexVBOindex = -1;
	indexesVBOindex = -1;
	normalVBOindex = -1;
	textureVBOindex = -1;
	VBOindex = 0;
}
void MeshStore::setVertexCoords(float *vt,int size){
	vertexCoord.erase(vertexCoord.begin(),vertexCoord.end());
	for(int i = 0;i < size;i++)vertexCoord.push_back(vt[i]);
	if(size > 0){//not nesseseray
		vertexVBOindex = VBOindex;
		VBOindex ++;
	}
}
void MeshStore::setNormalCoords(float *vt,int size){
	normalCoord.erase(normalCoord.begin(),normalCoord.end());
	for(int i = 0;i < size;i++)normalCoord.push_back(vt[i]);
		if(size > 0){//not nesseseray
		normalVBOindex = VBOindex;
		VBOindex ++;
	}
}
void MeshStore::setColorCoords(float *vt,int size){
	colorCoord.erase(colorCoord.begin(),colorCoord.end());
	for(int i = 0;i < size;i++)colorCoord.push_back(vt[i]);
	if(size > 0){//not nesseseray
		colorVBOindex = VBOindex;
		VBOindex ++;
	}
}
void MeshStore::setTextureCoords(float *vt,int size){
	textureCoord.erase(textureCoord.begin(),textureCoord.end());
	for(int i = 0;i < size;i++)textureCoord.push_back(vt[i]);
	if(size > 0){//not nesseseray
		textureVBOindex = VBOindex;
		VBOindex ++;
	}
}
void MeshStore::setIndexes(unsigned int *vt,int size){
	indexes.erase(indexes.begin(),indexes.end());
	for(int i = 0;i < size;i++)
		indexes.push_back(vt[i]);
	if(size > 0){//not nesseseray
		indexesVBOindex = VBOindex;
		VBOindex ++;
	}
}
void MeshStore::uniteMeshStore(MeshStore &ms){
	int indexPlus = (vertexCoord.size() / 3);
	vertexCoord.insert(vertexCoord.end(),ms.vertexCoord.begin(),ms.vertexCoord.end());
	colorCoord.insert(colorCoord.end(),ms.colorCoord.begin(),ms.colorCoord.end());
	normalCoord.insert(normalCoord.end(),ms.normalCoord.begin(),ms.normalCoord.end());
	textureCoord.insert(textureCoord.end(),ms.textureCoord.begin(),ms.textureCoord.end());
	for(unsigned int i = 0;i < ms.getIndexes().size();i++)
		ms.getIndexes()[i] += indexPlus;
	indexes.insert(indexes.end(),ms.getIndexes().begin(),ms.getIndexes().end());
	//tamamen ayný koþullarda olmalarý gerekiyor yoksa bozulur
}
	   /********MESH********/
void Mesh::createMesh(MeshStore &ms){
	GLuint VBOSize,*VBO;
	VBOSize = ms.VBOindex;
	VBO = new GLuint[VBOSize];
	glGenBuffers(VBOSize,&VBO[0]);
	if(ms.vertexVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VBO[ms.vertexVBOindex]); 
		glBufferData(GL_ARRAY_BUFFER,ms.getVertexCoord().size()*sizeof(float),NULL,GL_STATIC_DRAW);
		VAOID.VERTEXVBO = VBO[ms.vertexVBOindex];
		VAOID.VertexSize = ms.getVertexCoord().size();
	}
	if(ms.colorVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VBO[ms.colorVBOindex]); 
		glBufferData(GL_ARRAY_BUFFER,ms.getColorCoord().size()*sizeof(float),NULL,GL_STATIC_DRAW);
		VAOID.COLORVBO = VBO[ms.colorVBOindex];
	}
	if(ms.textureVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VBO[ms.textureVBOindex]); 
		glBufferData(GL_ARRAY_BUFFER,ms.getTextureCoord().size()*sizeof(float),NULL,GL_STATIC_DRAW);
		VAOID.TEXTUREVBO = VBO[ms.textureVBOindex];
		VAOID.texture_id = ms.getTextureId();
	}
	if(ms.normalVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VBO[ms.normalVBOindex]); 
		glBufferData(GL_ARRAY_BUFFER,ms.getNormalCoord().size()*sizeof(float),NULL,GL_STATIC_DRAW);
		VAOID.NORMALVBO = VBO[ms.normalVBOindex];
	}
	if(ms.getIndexes().size() > 0){
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,VBO[ms.indexesVBOindex]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,ms.getIndexes().size()*sizeof(int),NULL,GL_STATIC_DRAW);
		VAOID.INDEXVBO = VBO[ms.indexesVBOindex];
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	}
	refreshMesh(ms);
}//it will return meshStore VAOID and we will use this for chancings
void Mesh::drawMesh(){
		if(VAOID.VERTEXVBO > 0){
			glBindBuffer(GL_ARRAY_BUFFER,VAOID.VERTEXVBO);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0,3,GL_FLOAT,false,0,0);
		}
		if(VAOID.TEXTUREVBO > 0){
			glBindBuffer(GL_ARRAY_BUFFER,VAOID.TEXTUREVBO);	
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1,2,GL_FLOAT,false,0,0);
		}
		if(VAOID.INDEXVBO > 0){
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,VAOID.INDEXVBO);
			glDrawElements(GL_TRIANGLES,VAOID.VertexSize,GL_UNSIGNED_INT,0);
		}	
		else glDrawArrays(GL_TRIANGLES,0,VAOID.VertexSize);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
	}
void Mesh::refreshMesh(MeshStore &ms){
	if(ms.vertexVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VAOID.VERTEXVBO); 
		glBufferSubData(GL_ARRAY_BUFFER,0,ms.getVertexCoord().size()*sizeof(float),&ms.getVertexCoord()[0]);
	}
	if(ms.colorVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VAOID.COLORVBO); 
		glBufferSubData(GL_ARRAY_BUFFER,0,ms.getColorCoord().size()*sizeof(float),&ms.getColorCoord()[0]);
	}
	if(ms.textureVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VAOID.TEXTUREVBO); 
		glBufferSubData(GL_ARRAY_BUFFER,0,ms.getTextureCoord().size()*sizeof(float),&ms.getTextureCoord()[0]);
	}

	if(ms.normalVBOindex >= 0){
		glBindBuffer(GL_ARRAY_BUFFER,VAOID.NORMALVBO); 
		glBufferSubData(GL_ARRAY_BUFFER,0,ms.getNormalCoord().size()*sizeof(float),&ms.getNormalCoord()[0]);
	}
	if(ms.getIndexes().size() > 0){
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,VAOID.INDEXVBO);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,0,ms.getIndexes().size()*sizeof(int),&ms.getIndexes()[0]);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
void Mesh::releaseMesh(){}
bool Mesh::isThereMesh(){
	if(VAOID.VertexSize > 0) return true;
	else false;
}
