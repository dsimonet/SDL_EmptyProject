#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

#include <SDL.h>
#include <SDL_image.h>

using namespace std;

string ExePath();
char * GetRelativePath( const char * _in);
SDL_Texture * loadTexture(SDL_Renderer * _renderer, string path );

#endif // __UTILS__
