#ifndef MESHGRID
#define MESHGRID

#include "RenderObject.hpp"

class MeshGrid : public RenderObject
{
public:
  MeshGrid();
  void createMeshGrid(int m, int n);
  void createMeshGridIndices(int m, int n);
};

#endif