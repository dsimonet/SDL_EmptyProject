#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <sstream>

#include <SDL.h>
#include <SDL_image.h>
#include "LText.h"

using namespace std;

string ExePath();
char * GetRelativePath( const char * _in);
SDL_Texture * loadTexture(SDL_Renderer * _renderer, string path );
void printHere(SDL_Renderer * gRenderer, char * t, int posX, int posY);

#endif // __UTILS__
