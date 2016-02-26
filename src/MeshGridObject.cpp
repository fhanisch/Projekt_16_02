#include "ogl.hpp"
#include "MeshGridObject.hpp"

MeshGridObject::MeshGridObject(GLuint sp, Matrix4* cam, MeshGrid *mesh) : RenderObject()
{
  shaderProgram = sp;
  mProj.setFrustum(0.25*(GLfloat)WND_WIDTH/(GLfloat)WND_HEIGHT,0.25,0.5,100.0);
  color = Vec4(1.0f, 0.0f, 0.0f, 1.0f);	
  renderMode = GL_TRIANGLES;
  initObj();
  mView = cam;
  uID = mesh->getUid();
  vID = mesh->getVid();
  iboID = mesh->getIBOid();
  indicesLen = mesh->getIndicesLen();
}

MeshGridObject::MeshGridObject(GLuint sp, Matrix4* cam, MeshGrid* mesh, Texture *tex) : RenderObject()
{
  MeshGridObject(sp, cam, mesh);
  texID[0] = tex->id;
}

MeshGridObject::MeshGridObject(GLuint sp, Matrix4* cam, MeshGrid* mesh, Texture* tex1, Texture* tex2) : RenderObject()
{
  MeshGridObject(sp, cam, mesh);
  texID[0] = tex1->id;
  texID[1] = tex2->id;
}

