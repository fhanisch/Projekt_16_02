#include <cstdlib>
#include "ogl.hpp"
#include "MeshGrid.hpp"

MeshGrid::MeshGrid()
{
	createMeshGrid(100, 100);
	createMeshGridIndices(100, 100);
	createVBO(GL_ARRAY_BUFFER, &uID, uSize, u);
	createVBO(GL_ARRAY_BUFFER, &vID, vSize, v);	
	createVBO(GL_ELEMENT_ARRAY_BUFFER, &iboID, indicesSize, (GLfloat*)indices);	
}

void MeshGrid::createMeshGrid(int m, int n)
{	
	unsigned int i,j;

	uSize = m*n*sizeof(float);
	vSize = m*n*sizeof(float);	
	u = (GLfloat*)malloc(uSize);
	v = (GLfloat*)malloc(vSize);

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			u[i*n+j]=(float)j/((float)n-1);
			v[j*m+i]=(float)j/((float)m-1);
		}	
}

void MeshGrid::createMeshGridIndices(int m, int n)
{
	uint i,j;

	indicesLen=3*2*(m-1)*(n-1);
	indicesSize = indicesLen * sizeof(uint);
	indices = (GLuint*)malloc(indicesSize);

	for(i=0;i<m-1;i++)
		for(j=0;j<n-1;j++)
		{
			indices[6*(i*(n-1)+j)+0]=i*n+j;
			indices[6*(i*(n-1)+j)+1]=i*n+j+1;
			indices[6*(i*(n-1)+j)+2]=(i+1)*n+j;

			indices[6*(i*(n-1)+j)+3]=i*n+j+1;
			indices[6*(i*(n-1)+j)+4]=(i+1)*n+j;
			indices[6*(i*(n-1)+j)+5]=(i+1)*n+j+1;
		}
}