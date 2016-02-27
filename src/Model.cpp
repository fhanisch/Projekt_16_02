#include "ogl.hpp"
#include "Model.hpp"

Model::Model(GLuint sp, char *filename, GLenum rm) : RenderObject()
{
  shaderProgram = sp;
  loadModel(filename);
  renderMode = rm;
  initObj();
}

Model::Model(GLuint sp, char* filename, Vec4 c, GLenum rm) : RenderObject()
{
  shaderProgram = sp;
  loadModel(filename);
  color=c;
  renderMode = rm;
  initObj();  
}

void Model::setRatio(GLfloat r)
{
  mProj.m11 = r;
}

void Model::setZdir(GLfloat z)
{
  mProj.m33 = z;
}
