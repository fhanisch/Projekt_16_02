/*
    Erstellt: 20.02.2016
    Autor: fh
*/

#include <iostream>
#include <SDL/SDL.h>
#include "ogl.hpp"
#include "Render.hpp"

using namespace std;

Render::Render(SDL_Event *e)
{
  event = e;
  frustum.setFrustum(0.25*(GLfloat)WND_WIDTH/(GLfloat)WND_HEIGHT,0.25,0.5,100.0);
}


void Render::initOpenGL()
{
  const GLubyte *vendor, *renderer, *oglVersion, *glslVersion;
  
  vendor	= glGetString(GL_VENDOR);
  renderer	= glGetString(GL_RENDERER);
  oglVersion	= glGetString(GL_VERSION);
  glslVersion	= glGetString(GL_SHADING_LANGUAGE_VERSION);
  
  cout << "Vendor: " << vendor << endl;
  cout << "Renderer: " << renderer << endl;
  cout << "OpenGL Version: " << oglVersion << endl;
  cout << "GLSL Version: " << glslVersion << endl;
  
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  //glEnable(GL_BLEND);
  //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClearDepth(1.0f);    
}

void Render::initRenderScene()
{
  shader = new Shader();
  shader->genShaderPrograms();
  camera = new Matrix4();
  camera->translate(0.0f, -2.0f, -5.0f);
  texBoden = new Texture( (GLchar*)"../res/laminat.bmp", GL_TEXTURE0);
  texFliessen = new Texture( (GLchar*)"../res/fliessen.bmp", GL_TEXTURE1);
  mesh = new MeshGrid();
  lines = new Model(shader->generic_sp, (char*)"../res/lines.geo",ROT, GL_LINES);
  triangle = new Model(shader->generic_sp, (char*)"../res/triangle.geo",LILA, GL_TRIANGLES);
  triangle->setRatio((GLfloat)WND_HEIGHT/(GLfloat)WND_WIDTH);
  triangle->mModel.scale(0.25f);
  triangle->mModel.translate(-0.5f, 0.5f, 0.0f);
  rect = new Model(shader->generic_sp, (char*)"../res/rectangle.geo", GREEN, GL_TRIANGLE_STRIP);
  rect->setRatio((GLfloat)WND_HEIGHT/(GLfloat)WND_WIDTH);
  rect->mModel.scale(0.25f);
  rect->mModel.translate(0.5f, -0.5f, 0.0f);
  circle = new Circle(shader->circle_sp);
  stern = new Model(shader->generic_sp, (char*)"../res/stern.geo", BLAU, GL_TRIANGLES);
  stern->setRatio((GLfloat)WND_HEIGHT/(GLfloat)WND_WIDTH);
  stern->setZdir(-1.0f);
  stern->mModel.scale(0.35f);
  stern->mModel.translate(0.5f, 0.5f, 0.1f);
  plane = new Model(shader->boden_sp, (char*)"../res/plane.geo", GL_TRIANGLE_STRIP);
  plane->setFrustum(frustum);
  plane->setCam(camera);
  plane->set2Texture(texBoden, texFliessen);
  plane->mModel.scale(20.0f);  
  cube = new Model(shader->ads_per_fragment_sp, (char*)"../res/cube.geo",TUERKIS,GL_QUADS);
  cube->setFrustum(frustum);
  cube->setCam(camera);
  cube->mModel.translate(-10.0f, 1.0f, -10.0f);  
  sphere[0] = new MeshGridObject(shader->sphere_sp, camera, mesh);
  sphere[0]->mModel.translate(0.0f, 1.0f, -5.0f);
  sphere[1] = new MeshGridObject(shader->sphere_sp, camera, mesh);
  sphere[1]->mModel.translate(0.0f, 1.0f, 5.0f);
  sphere[1]->color = Vec4(1.0f, 0.0f, 1.0f, 1.0f);
  sphere[2] = new MeshGridObject(shader->sphere_sp, camera, mesh);
  sphere[2]->mModel.translate(-5.0f, 1.0f, 0.0f);
  sphere[2]->color = Vec4(0.0f, 0.0f, 1.0f, 1.0f);
  sphere[3] = new MeshGridObject(shader->sphere_sp, camera, mesh);
  sphere[3]->mModel.translate(5.0f, 1.0f, 0.0f);
  sphere[3]->color = Vec4(1.0f, 1.0f, 0.0f, 1.0f);
  apfel = new MeshGridObject(shader->apfel_sp, camera, mesh);
  apfel->mModel.rotateX(-0.3);
  apfel->mModel.rotateZ(0.3);
  apfel->mModel.translate(0.0f, 1.5f, 0.0f);
  apfel->color = Vec4(0.0f, 1.0f, 0.0f, 1.0f);
}

void Render::renderLoop()
{
  boolean quit = false;
  boolean f1 = true; 
  boolean f2 = false;
  float ds = 0.02f;
  float dphi = 0.004f;
  
  memset(key, 0, sizeof(key));
  
  while(!quit)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(f1)
    {
      lines->drawObj();
      triangle->drawObj();
      rect->drawObj();
      circle->drawObj();
      stern->drawObj();      
    }
    if(f2)
    {
      plane->drawObj();
      cube->drawObj();
      sphere[0]->drawObj();
      sphere[1]->drawObj();
      sphere[2]->drawObj();
      sphere[3]->drawObj();
      apfel->drawObj();
    }
    
    SDL_GL_SwapBuffers();
    
    while(SDL_PollEvent(event))
    {
      switch(event->type)
      {
      case SDL_QUIT: 
	quit=1;
	break;
      case SDL_KEYDOWN:
	key[event->key.keysym.sym] = true;	
	break;
      case SDL_KEYUP:
	key[event->key.keysym.sym] = false;	
	break;
//       case SDL_MOUSEMOTION:
// 	mouseX = event.motion.xrel;
// 	mouseY = event.motion.yrel;
// 	break;
      }
    }
    if (key[SDLK_ESCAPE]) quit=true;
    if (key[SDLK_F1]) {f1=true; f2=false;}
    if (key[SDLK_F2]) {f1=false; f2=true;}    
    if(f1)
    {
      //if (key[SDLK_LEFT]) stern->mModel.rotateZ(-0.01);
      //if (key[SDLK_RIGHT]) stern->mModel.rotateZ(0.01);
      if (key[SDLK_LEFT]) stern->mModel = stern->mModel * Matrix4().getRotZ(-0.005);
      if (key[SDLK_RIGHT]) stern->mModel = stern->mModel * Matrix4().getRotZ(0.005);
      if (key[SDLK_UP]) stern->mModel = Matrix4().getRotZ(-0.005) * stern->mModel;
      if (key[SDLK_DOWN]) stern->mModel = Matrix4().getRotZ(0.005) * stern->mModel;
    }
    if(f2)
    {
      if (key[SDLK_w]) camera->translate(0.0, 0.0, ds);
      if (key[SDLK_s]) camera->translate(0.0, 0.0, -ds);
      if (key[SDLK_a]) camera->translate(ds, 0.0, 0.0);
      if (key[SDLK_d]) camera->translate(-ds, 0.0, 0.0);
      if (key[SDLK_y])
      {
	rotAxis = camera->getXAxis() * camera->getZAxis();
	camera->translate(rotAxis.x*ds, rotAxis.y*ds, rotAxis.z*ds);
      }
      if (key[SDLK_x])
      {
	rotAxis = camera->getXAxis() * camera->getZAxis();
	camera->translate(rotAxis.x*-ds, rotAxis.y*-ds, rotAxis.z*-ds);
      }
      if (key[SDLK_LEFT])
      {
	rotAxis = camera->getXAxis() * camera->getZAxis();
	*camera = Matrix4().getRotX(rotAxis.x*dphi) * *camera;
	*camera = Matrix4().getRotY(rotAxis.y*dphi) * *camera;
	*camera = Matrix4().getRotZ(rotAxis.z*-dphi) * *camera;
      }
      if (key[SDLK_RIGHT])
      {
	rotAxis = camera->getXAxis() * camera->getZAxis();
	*camera = Matrix4().getRotX(rotAxis.x*-dphi) * *camera;
	*camera = Matrix4().getRotY(rotAxis.y*-dphi) * *camera;
	*camera = Matrix4().getRotZ(rotAxis.z*dphi) * *camera;
      }
      if (key[SDLK_UP]) *camera = Matrix4().getRotX(-dphi) * *camera;
      if (key[SDLK_DOWN]) *camera = Matrix4().getRotX(dphi) * *camera;
    }
    
    //SDL_Delay(3);
  }
}
