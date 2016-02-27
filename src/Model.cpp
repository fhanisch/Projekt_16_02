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

void Model::setCam(Matrix4 *cam)
{
  mView = cam;
}

void Model::setFrustum(Matrix4 frustum)
{
  mProj = frustum;
}

void Model::setTexture(Texture* tex)
{
  texID[0] = tex->id;
}

void Model::set2Texture(Texture* tex1, Texture* tex2)
{
  texID[0] = tex1->id;
  texID[1] = tex2->id;
}
