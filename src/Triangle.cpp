#include <GL/gl.h>
#include "Triangle.hpp"

Triangle::Triangle(GLuint sp) : RenderObject()
{
  shaderProgram = sp;
  GLfloat vert[] = {-1.0f,-1.0f, 0.0f,
		     1.0f,-1.0f, 0.0f,
		     0.0f, 1.0f, 0.0f};
  GLuint ind[] = {0,1,2};
	  
  vertices = vert;
  verticesSize = sizeof(vert);
  indices = ind;
  indicesLen = 3;
  indicesSize = sizeof(ind);
  mProj.m11 = (GLfloat)WND_HEIGHT/(GLfloat)WND_WIDTH;
  mModel.scale(0.25f);
  mModel.translate(-0.5f, 0.5f, 0.0f);
  color = Vec4(1.0f, 0.0f, 1.0f, 1.0f);
  renderMode = GL_TRIANGLES;	
  initObj();
}
