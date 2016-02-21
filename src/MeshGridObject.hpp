#include "MeshGrid.hpp"
#include "Texture.hpp"

class MeshGridObject : public RenderObject
{
public:
  MeshGridObject(GLuint sp, Matrix4 *cam, MeshGrid *mesh);
  MeshGridObject(GLuint sp, Matrix4 *cam, MeshGrid *mesh, Texture *tex);
  MeshGridObject(GLuint sp, Matrix4 *cam, MeshGrid *mesh, Texture *tex1, Texture *tex2);
  
};