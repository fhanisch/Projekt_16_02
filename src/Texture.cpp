#include <cstdio>
#include <stdlib.h>
#include "ogl.hpp"
#include "Texture.hpp"

Texture::Texture(GLchar* filename, GLenum texindex)
{
  fileName = filename;
  textureIndex = texindex;
  loadTexture();
  glActiveTexture(textureIndex);
  bindTexture();
}

int Texture::loadTexture()
{
	char signature[2];
	unsigned short farbtiefe;
	unsigned int offset;
	unsigned int bytePtr=0;
	unsigned int x,y;
		
	FILE *file = fopen(fileName,"r");
	fseek(file,0,SEEK_SET);
	fread(signature,2,1,file);	
	fseek(file,28,SEEK_SET);
	fread(&farbtiefe,2,1,file);	
	fseek(file,18,SEEK_SET);
	fread(&xSize,4,1,file);
	fread(&ySize,4,1,file);
	texture = (GLubyte*)malloc(xSize*ySize*4);
	fseek(file,10,SEEK_SET);
	fread(&offset,4,1,file);	
	fseek(file,offset,SEEK_SET);
	for (y=0;y<ySize;y++)
	{
		for (x=0;x<xSize;x++)
		{
			fread(texture+bytePtr+2,1,1,file);
			fread(texture+bytePtr+1,1,1,file);
			fread(texture+bytePtr,1,1,file);
			texture[bytePtr+3] = 0xff;
			bytePtr+=4;
		}
		fseek(file,xSize%4,SEEK_CUR);
	}

	fclose(file);
	return 0;
}

void Texture::bindTexture()
{	
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D,id);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, xSize, ySize, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);
}
