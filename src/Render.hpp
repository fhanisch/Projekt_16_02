#include "Shader.hpp"
#include "MeshGrid.hpp"
#include "Texture.hpp"
#include "Lines.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Stern.hpp"
#include "Plane.hpp"
#include "Cube.hpp"
#include "MeshGridObject.hpp"

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
  RenderObject *lines, *triangle, *rect, *circle, *stern, *plane, *cube, *sphere[4], *apfel;
public:
  Render(SDL_Event *e);
  void initOpenGL();
  void initRenderScene();
  void renderLoop();
};