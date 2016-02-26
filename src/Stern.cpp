#include "ogl.hpp"
#include "Stern.hpp"

Stern::Stern(GLuint sp) : RenderObject()
{
  shaderProgram = sp;

  GLfloat vert[] = {  0.0f,  -1.0f, 0.0f,
		     0.25f, -0.25f, 0.0f,
		      1.0f,   0.0f, 0.0f,
		     0.25f,  0.25f, 0.0f,
		      0.0f,   1.0f, 0.0f,
		    -0.25f,  0.25f, 0.0f,
		     -1.0f,   0.0f, 0.0f,
		    -0.25f, -0.25f, 0.0f};

  GLuint ind[] = {0,1,7, 1,2,3, 3,4,5, 5,6,7, 1,3,5, 5,7,1};
	  
  vertices = vert;
  verticesSize = sizeof(vert);
  indices = ind;
  indicesLen = 18;
  indicesSize = sizeof(ind);
  mProj.m11 = (GLfloat)WND_HEIGHT/(GLfloat)WND_WIDTH;
  mProj.m33 = -1.0;
  mModel.scale(0.35f);
  mModel.translate(0.5f, 0.5f, 0.1f);
  color = Vec4(0.0f, 0.0f, 1.0f, 1.0f);	
  renderMode = GL_TRIANGLES;
initObj();
}
