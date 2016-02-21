#include <GL/gl.h>
#include "Circle.hpp"

Circle::Circle(GLuint sp) : RenderObject()
{
  shaderProgram = sp;
  u = vecf(0.0f, 1.0f, 100);
  uSize = 100*sizeof(GLfloat);
  indices = veci(0,100);
  indicesLen = 100;
  indicesSize = 100*sizeof(GLuint);
  mProj.m11 = (GLfloat)WND_HEIGHT/(GLfloat)WND_WIDTH;
  mModel.scale(0.25f);
  mModel.translate(-0.5f, -0.5f, 0.0f);
  color = Vec4(1.0f, 1.0f, 0.0f, 1.0f);
  renderMode = GL_POLYGON;	
  initObj();
}
