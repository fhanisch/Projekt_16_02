#include <cstdio>
#include <cstdlib>
#include "ogl.hpp"
#include "Shader.hpp"

typedef unsigned int uint;

using namespace std;

int Shader::loadShader(GLchar **shaderStr, char *fileName)
{
	uint filesize;
	uint readElements;
	FILE *file = fopen(fileName,"r");

	fseek(file,0,SEEK_END);
	filesize=ftell(file);
	rewind(file);	
	*shaderStr = (GLchar*)malloc(filesize+1);
	readElements = fread(*shaderStr,filesize,1,file);	
	(*shaderStr)[filesize]='\0';
	fclose(file);

	return 0;
}

GLuint Shader::createShader(GLenum shaderType, const GLchar *shaderStr)
{
	GLuint shader;

	shader = glCreateShader(shaderType);
	glShaderSource(shader,1,&shaderStr,NULL);
	glCompileShader(shader);		

	return shader;
}

GLuint Shader::createShaderProgram(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	return shaderProgram;
}

void Shader::genShaderPrograms()
{
	//Load Vertex Shader
	loadShader(&generic_vs_str, (char*)GENERIC_VS_FILENAME);
	loadShader(&circle_vs_str, (char*)CIRCLE_VS_FILENAME);
	loadShader(&ads_per_fragment_vs_str, (char*)ADS_PER_FRAGMENT_VS_FILENAME);
	loadShader(&sphere_ads_per_fragment_vs_str, (char*)SPHERE_ADS_PER_FRAGMENT_VS_FILENAME);
	loadShader(&apfel_vs_str, (char*)APFEL_VS_FILENAME);
	loadShader(&normal_mapping_vs_str, (char*)NORMAL_MAPPING_VS_FILENAME);

	//Load Fragment Shader
	loadShader(&generic_fs_str, (char*)GENERIC_FS_FILENAME);
	loadShader(&ads_per_fragment_fs_str, (char*)ADS_PER_FRAGMENT_FS_FILENAME);
	loadShader(&ads_per_fragment_plane_fs_str, (char*)ADS_PER_FRAGMENT_PLANE_FS_FILENAME);
	loadShader(&normal_mapping_fs_str, (char*)NORMAL_MAPPING_FS_FILENAME);

	//Create Vertex Shader
	generic_vs = createShader(GL_VERTEX_SHADER, generic_vs_str);
	circle_vs = createShader(GL_VERTEX_SHADER, circle_vs_str);
	ads_per_fragment_vs = createShader(GL_VERTEX_SHADER, ads_per_fragment_vs_str);
	sphere_ads_per_fragment_vs = createShader(GL_VERTEX_SHADER, sphere_ads_per_fragment_vs_str);
	apfel_vs = createShader(GL_VERTEX_SHADER, apfel_vs_str);
	normal_mapping_vs = createShader(GL_VERTEX_SHADER, normal_mapping_vs_str);

	//Create Fragment Shader
	generic_fs = createShader(GL_FRAGMENT_SHADER, generic_fs_str);
	ads_per_fragment_fs = createShader(GL_FRAGMENT_SHADER, ads_per_fragment_fs_str);
	ads_per_fragment_plane_fs = createShader(GL_FRAGMENT_SHADER, ads_per_fragment_plane_fs_str);
	normal_mapping_fs = createShader(GL_FRAGMENT_SHADER, normal_mapping_fs_str);

	//Create Shader Programs
	generic_sp = createShaderProgram(generic_vs, generic_fs);
	circle_sp = createShaderProgram(circle_vs, generic_fs);
	ads_per_fragment_sp = createShaderProgram(ads_per_fragment_vs, ads_per_fragment_fs);
	boden_sp = createShaderProgram(ads_per_fragment_vs, ads_per_fragment_plane_fs);
	sphere_sp = createShaderProgram(sphere_ads_per_fragment_vs, ads_per_fragment_fs);
	apfel_sp = createShaderProgram(apfel_vs, ads_per_fragment_fs);
	normal_mapping_sp = createShaderProgram(normal_mapping_vs, normal_mapping_fs);
}
