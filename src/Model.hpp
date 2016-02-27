#include "RenderObject.hpp"
#include "Texture.hpp"

class Model : public RenderObject
{
public:
  Model(GLuint sp, char *filename, GLenum rm);
  Model(GLuint sp, char *filename, Vec4 c, GLenum rm);
  void setRatio(GLfloat r);
  void setZdir(GLfloat z);
  void setCam(Matrix4 *cam);
  void setFrustum(Matrix4 frustum);
  void setTexture(Texture *tex);
  void set2Texture(Texture *tex1, Texture *tex2);
};
