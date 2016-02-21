#ifndef TEXTURE
#define TEXTURE

class Texture
{
public:
  GLuint id;
protected:
  GLchar *fileName;
  GLubyte *texture;
  GLenum textureIndex;  
  int xSize, ySize;
public:
  Texture(GLchar *filename, GLenum texindex);
protected:
  int loadTexture();
  void bindTexture();
};

#endif