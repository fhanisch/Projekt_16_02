#include "RenderObject.hpp"
#include "Texture.hpp"

class Plane : public RenderObject
{
public:
  Plane(GLuint sp, Matrix4 *cam);
  Plane(GLuint sp, Matrix4 *cam, Texture *tex);
  Plane(GLuint sp, Matrix4 *cam, Texture *tex1, Texture *tex2);
  void init(GLuint sp, Matrix4 *cam);
};