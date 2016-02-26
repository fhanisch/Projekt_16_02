/*
    Erstellt: 17.02.2016
    Autor: fh
*/

#include <iostream>
#include <SDL/SDL.h>
#include "ogl.hpp"
#include "Render.hpp"

using namespace std;

SDL_Event event;

int initOpenGLWindow(char *wndName)
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE,8 );
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

  SDL_SetVideoMode(WND_WIDTH,WND_HEIGHT,32,SDL_OPENGL|SDL_FULLSCREEN);
  SDL_WM_SetCaption(wndName, NULL);

  return 0;
}


int main(int argc, char **argv)
{
  Render *render = new Render(&event);
  
  cout << "Programm: " << argv[0]+2 << endl;
  cout << "Autor: fh" << endl;
  if (initOpenGLWindow(argv[0]+2)!=0) return 1;
  cout << "SDL initialized" << endl;
  if (glewInit()!=0) return 1;
  cout << "GLEW initialized" << endl;
  
  render->initOpenGL();
  render->initRenderScene();
  render->renderLoop();
  
  SDL_Quit();
  
  return 0;
}
