#include "ogl.hpp"
#include "Lines.hpp"

Lines::Lines(GLuint sp) : RenderObject()
{				
	shaderProgram = sp;
	GLfloat vert[] = {	 0.0f,-1.0f, 0.0f,
			 	-1.0f, 0.0f, 0.0f,
			 	 0.0f, 1.0f, 0.0f,
				 1.0f, 0.0f, 0.0f};
	GLuint ind[] = {0,2,1,3};
		
	vertices = vert;
	verticesSize = sizeof(vert);
	indices = ind;
	indicesLen = 4;
	indicesSize = sizeof(ind);
	
	mProj = Matrix4();
	mModel = Matrix4();
	color = Vec4(1.0f, 0.0f, 0.0f, 1.0f);			
	renderMode = GL_LINES;	
	initObj();	
}