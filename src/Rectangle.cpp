#include "ogl.hpp"
#include "Rectangle.hpp"

Rectangle::Rectangle(GLuint sp) : RenderObject()
{
  shaderProgram = sp;
  GLfloat vert[] = {-1.0f,-1.0f, 0.0f,
		     1.0f,-1.0f, 0.0f,
		    -1.0f, 1.0f, 0.0f,
		     1.0f, 1.0f, 0.0f};
  GLuint ind[] = {0,1,2,3};
  
  vertices = vert;
  verticesSize = sizeof(vert);
  indices = ind;
  indicesLen = 4;
  indicesSize = sizeof(ind);  
  mProj.m11 = (GLfloat)WND_HEIGHT/(GLfloat)WND_WIDTH;
  mModel.scale(0.25f);
  mModel.translate(0.5f, -0.5f, 0.0f);
  color = Vec4(0.0f, 1.0f, 0.0f, 1.0f);
  renderMode = GL_TRIANGLE_STRIP;	
  initObj();
}

