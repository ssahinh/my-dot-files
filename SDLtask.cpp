/*
Compile command:
g++ -o test main.cpp -lSDLmain -lSDL -lGL
 */
 
// specific headers
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <iostream>
 
//start of the program
int main( int argc, char* args[] )
{
  //initialize SDL
  SDL_Init(SDL_INIT_EVERYTHING);
 
  //Set OpenGL memory usage
  SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
 
 
  //Caption of the window
  SDL_WM_SetCaption( "Our first game", NULL );
 
  //Size of the window
  SDL_SetVideoMode(600,400,32, SDL_OPENGL );
 
  //Specific the clear color
  glClearColor(1,1,1,1); //RED,GREEN,BLUE,ALPHA
 
  //What portion of the screen we will display
  glViewport(0,0,600,400);
 
  //Shader model - Use this
  glShadeModel(GL_SMOOTH);
 
  //2D rendering
  glMatrixMode(GL_PROJECTION);
 
  //"Save" it
  glLoadIdentity();
 
  //Disable depth checking
  glDisable(GL_DEPTH_TEST);
 
  std::cout << "OpenGL is running\n";
  std::cout << "Main loop has started\n";
 
  //Handles the main loop
  bool isRunning = true;
 
  //For handling with event
  SDL_Event event;
 
  //Main game loop
  while ( isRunning )
    {
      //EVENTS
      while ( SDL_PollEvent(&event) )
        {
          //if the window was closed
          if ( event.type == SDL_QUIT )
            {
              isRunning = false;
            }
 
          //If a button was released and the button is escape
          if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE )
            {
              isRunning = false;
            }
 
          if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r )
            {
              glClearColor(1,0,0,1);
            }
          //logic that should happen for a certain event
        }
 
      //LOGIC
 
      //RENDERING to the screen
      glClear(GL_COLOR_BUFFER_BIT);
 
      glPushMatrix(); //Start rendering phase
 
      glOrtho(0,600,400,0,-1,1); //Set the matrix
 
      glColor4ub(255,0,0,255); //Red color
 
      glBegin(GL_QUADS); //GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_QUADS, GL_TRIANGLES, GL_POLIGON
 
      glVertex2f(5,5); //top left corner
      glVertex2f(595,5); //upper right corner
 
      glColor4ub(0,255,0,255); //green color
 
      glVertex2f(595,395); //down right corner
      glVertex2f(5,395); //down left corner
 
      glEnd(); //End drawing
 
      glColor4ub(0,0,0,255); //Black color
 
      glBegin(GL_LINES); //draw lines
 
      //First line
      glVertex2f(5,5);
      glVertex2f(595,395);
 
      //Second line
      glVertex2f(595,5);
      glVertex2f(5,395);
 
      glEnd(); //SEnd drawing
 
      glPopMatrix(); //End rendering phase
 
      SDL_GL_SwapBuffers();
    }
 
  SDL_Quit();
 
  return 0;
}