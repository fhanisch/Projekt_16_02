#include <GL/gl.h>
#include "Cube.hpp"

Cube::Cube(GLuint sp, Matrix4* cam) : RenderObject()
{
  shaderProgram = sp;
	  
  GLfloat vert[] = {	-1.0f, -1.0f, -1.0f,
			    1.0f, -1.0f, -1.0f,
			  -1.0f, -1.0f,  1.0f,
			    1.0f, -1.0f,  1.0f,

			  -1.0f,  1.0f, -1.0f,
			    1.0f,  1.0f, -1.0f,
			  -1.0f,  1.0f,  1.0f,
			    1.0f,  1.0f,  1.0f,

			  -1.0f, -1.0f,  1.0f,
			    1.0f, -1.0f,  1.0f,
			  -1.0f,  1.0f,  1.0f,
			    1.0f,  1.0f,  1.0f,

			  -1.0f, -1.0f, -1.0f,
			    1.0f, -1.0f, -1.0f,
			  -1.0f,  1.0f, -1.0f,
			    1.0f,  1.0f, -1.0f,

			    1.0f, -1.0f, -1.0f,
			    1.0f, -1.0f,  1.0f,
			    1.0f,  1.0f, -1.0f,
			    1.0f,  1.0f,  1.0f,

			  -1.0f, -1.0f, -1.0f,
			  -1.0f, -1.0f,  1.0f,
			  -1.0f,  1.0f, -1.0f,
			  -1.0f,  1.0f,  1.0f};

  GLfloat norm[] = {	 0.0f, -1.0f,  0.0f,
			    0.0f, -1.0f,  0.0f,
			    0.0f, -1.0f,  0.0f,
			    0.0f, -1.0f,  0.0f,

			    0.0f,  1.0f,  0.0f,
			    0.0f,  1.0f,  0.0f,
			    0.0f,  1.0f,  0.0f,
			    0.0f,  1.0f,  0.0f,

			    0.0f,  0.0f,  1.0f,
			    0.0f,  0.0f,  1.0f,
			    0.0f,  0.0f,  1.0f,
			    0.0f,  0.0f,  1.0f,

			    0.0f,  0.0f, -1.0f,
			    0.0f,  0.0f, -1.0f,
			    0.0f,  0.0f, -1.0f,
			    0.0f,  0.0f, -1.0f,

			    1.0f,  0.0f,  0.0f,
			    1.0f,  0.0f,  0.0f,
			    1.0f,  0.0f,  0.0f,
			    1.0f,  0.0f,  0.0f,

			  -1.0f,  0.0f,  0.0f,
			  -1.0f,  0.0f,  0.0f,
			  -1.0f,  0.0f,  0.0f,
			  -1.0f,  0.0f,  0.0f};

  GLuint ind[] = {0,1,3,2, 4,5,7,6, 8,9,11,10, 12,13,15,14, 16,17,19,18, 20,21,23,22};
	  
  vertices = vert;
  verticesSize = sizeof(vert);
  normals = norm;
  normalsSize = sizeof(norm);
  indices = ind;
  indicesLen = 24;
  indicesSize = sizeof(ind);
  mProj.setFrustum(0.25*(GLfloat)WND_WIDTH/(GLfloat)WND_HEIGHT,0.25,0.5,100.0);  
  color = Vec4(0.0f, 1.0f, 0.0f, 1.0f);
  renderMode = GL_QUADS;
  mView = cam;
  initObj();
}
