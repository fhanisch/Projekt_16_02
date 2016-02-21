#include <GL/glew.h>
#include <GL/gl.h>
#include "RenderObject.hpp"

RenderObject::RenderObject()
{
  vertices = NULL;
  indices = NULL;
  normals = NULL;
  u = NULL;
  v = NULL;
  texCoords = NULL;
  vboID = 0;
  nboID = 0;
  uID = 0;
  vID = 0;
  iboID = 0;
  tcoID = 0;
  texID[0] = 0;
  texID[1] = 0; 
  mView = new Matrix4();
}


void RenderObject::createVBO(GLenum bufferType, GLuint *bufferID, GLuint bufferSize, GLfloat *buffer)
{	
	glGenBuffers(1,bufferID);
	glBindBuffer(bufferType, *bufferID);
	glBufferData(bufferType, bufferSize, buffer, GL_STATIC_DRAW);
}

void RenderObject::initObj()
{	
	if (vertices!=NULL)	
	{
		createVBO(GL_ARRAY_BUFFER, &vboID, verticesSize, vertices);		
	}

	if (u!=NULL)
	{
		createVBO(GL_ARRAY_BUFFER, &uID,uSize,u);			
	}

	if (v!=NULL)
	{
		createVBO(GL_ARRAY_BUFFER ,&vID,vSize,v);			
	}

	if (normals!=NULL)
	{
		createVBO(GL_ARRAY_BUFFER, &nboID, normalsSize, normals);		
	}

	if (texCoords!=NULL)
	{
		createVBO(GL_ARRAY_BUFFER, &tcoID, texCoordsSize, texCoords);
	}

	if (indices!=NULL)
	{
		createVBO(GL_ELEMENT_ARRAY_BUFFER, &iboID, indicesSize, (GLfloat*)indices);
	}

	mProjHandle = glGetUniformLocation(shaderProgram,"mProj");
	mViewHandle = glGetUniformLocation(shaderProgram,"mView");
	mModelHandle = glGetUniformLocation(shaderProgram,"mModel");
	colorHandle = glGetUniformLocation(shaderProgram,"color");
	samplerHandle[0] = glGetUniformLocation(shaderProgram,"samp");
	samplerHandle[1] = glGetUniformLocation(shaderProgram,"samp2");
}

void RenderObject::drawObj()
{
	GLuint location = 0;
	glUseProgram(shaderProgram);

	glUniformMatrix4fv(mProjHandle,1, GL_TRUE, (GLfloat*)&mProj);
	glUniformMatrix4fv(mViewHandle,1, GL_TRUE, (GLfloat*)mView);
	glUniformMatrix4fv(mModelHandle,1, GL_TRUE, (GLfloat*)&mModel);
	glUniform4fv(colorHandle,1, (GLfloat*)&color);

	if (samplerHandle[0]>=0) glUniform1i(samplerHandle[0],0);
	if (samplerHandle[1]>=0) glUniform1i(samplerHandle[1],1);
			
	if (vboID)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glEnableVertexAttribArray(location);
		glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, 0);
		location++;
	}
	
	if (nboID)
	{		
		glBindBuffer(GL_ARRAY_BUFFER, nboID);
		glEnableVertexAttribArray(location);
		glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, 0);
		location++;
	}
	
	if (uID)
	{
		glBindBuffer(GL_ARRAY_BUFFER, uID);
		glEnableVertexAttribArray(location);
		glVertexAttribPointer(location, 1, GL_FLOAT, GL_FALSE, 0, 0);
		location++;
	}

	if (vID)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vID);
		glEnableVertexAttribArray(location);
		glVertexAttribPointer(location, 1, GL_FLOAT, GL_FALSE, 0, 0);
		location++;
	}

	if (tcoID)
	{
		glBindBuffer(GL_ARRAY_BUFFER, tcoID);
		glEnableVertexAttribArray(location);
		glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, 0, 0);
		location++;
	}
	
	if (texID[0]) glBindTexture(GL_TEXTURE_2D,texID[0]);
	if (texID[1]) glBindTexture(GL_TEXTURE_2D,texID[1]);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);	
	glDrawElements(renderMode, indicesLen, GL_UNSIGNED_INT, 0);
}