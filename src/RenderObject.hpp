#ifndef RENDEROBJECT
#define RENDEROBJECT

#include "Matrix.hpp"

#define WND_WIDTH 1920
#define WND_HEIGHT 1080

class RenderObject
{
public:
  Matrix4 mModel;
  Vec4 color;
protected:
  GLuint shaderProgram, vboID, nboID, iboID, uID, vID, tcoID, texID[2];
  GLint mProjHandle, mViewHandle, mModelHandle, colorHandle, samplerHandle[2];		
  GLfloat *vertices, *normals, *u, *v, *texCoords;
  GLuint *indices;
  GLuint verticesSize, normalsSize, uSize, vSize, texCoordsSize, indicesLen, indicesSize;  
  Matrix4 mProj;
  Matrix4 *mView;  
  GLenum renderMode;  
public:
  RenderObject();
  void drawObj();
  GLuint getUid() {return uID;}
  GLuint getVid() {return vID;}
  GLuint getIBOid() {return iboID;}
  GLuint getIndicesLen() {return indicesLen;}
protected:  
  void createVBO(GLenum bufferType, GLuint *bufferID, GLuint bufferSize, GLfloat *buffer);
  void initObj();  
};

#endif