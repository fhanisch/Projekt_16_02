#include "Shader.hpp"
#include "MeshGrid.hpp"
#include "Texture.hpp"
#include "Model.hpp"
#include "Circle.hpp"
#include "Plane.hpp"
#include "Cube.hpp"
#include "MeshGridObject.hpp"

#define ROT Vec4(1.0f, 0.0f, 0.0f, 1.0f)
#define GREEN Vec4(0.0f, 1.0f, 0.0f, 1.0f)
#define BLAU Vec4(0.0f, 0.0f, 1.0f, 1.0f)
#define LILA Vec4(1.0f, 0.0f, 1.0f, 1.0f)

typedef unsigned int boolean;

class Render
{
protected:
  SDL_Event *event;
  boolean key[512];
  Shader *shader;
  Matrix4 *camera;
  Texture *texBoden, *texFliessen, *texSteine, *texSteineNorm;
  Vec3 rotAxis;
  MeshGrid *mesh;
  Model *lines, *triangle, *rect, *stern;
  RenderObject *circle, *plane, *cube, *sphere[4], *apfel;
public:
  Render(SDL_Event *e);
  void initOpenGL();
  void initRenderScene();
  void renderLoop();
};