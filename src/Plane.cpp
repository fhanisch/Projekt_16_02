#include "ogl.hpp"
#include "Plane.hpp"

Plane::Plane(GLuint sp, Matrix4 *cam) : RenderObject()
{
  init(sp, cam);
}

Plane::Plane(GLuint sp, Matrix4* cam, Texture *tex) : RenderObject()
{
  init(sp, cam);
  texID[0] = tex->id;
}

Plane::Plane(GLuint sp, Matrix4* cam, Texture *tex1, Texture *tex2) : RenderObject()
{
  init(sp, cam);
  texID[0] = tex1->id;
  texID[1] = tex2->id;
}

void Plane::init(GLuint sp, Matrix4* cam)
{
  shaderProgram = sp;
	  
  GLfloat vert[] = {	-1.0f, 0.0f, -1.0f,
			 1.0f, 0.0f, -1.0f,
			-1.0f, 0.0f,  1.0f,
			 1.0f, 0.0f,  1.0f};

  GLfloat norm[] = {	 0.0f, 1.0f,  0.0f,
			 0.0f, 1.0f,  0.0f,
			 0.0f, 1.0f,  0.0f,
			 0.0f, 1.0f,  0.0f};

  GLfloat coords[] = {	 0.0f, 0.0f,
			 1.0f, 0.0f,
			 0.0f, 1.0f,
			 1.0f, 1.0f};
			 
  GLuint ind[] = {0,1,2,3};

  vertices = vert;
  verticesSize = sizeof(vert);
  normals = norm;
  normalsSize = sizeof(norm);
  texCoords = coords;
  texCoordsSize = sizeof(coords);
  indices = ind;
  indicesLen = 4;
  indicesSize = sizeof(ind);
  mProj.setFrustum(0.25*(GLfloat)WND_WIDTH/(GLfloat)WND_HEIGHT,0.25,0.5,100.0);
  color = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
  renderMode = GL_TRIANGLE_STRIP;
  mView = cam;
  initObj();
}

