#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <sstream>

#include <SDL_ttf.h>
#include "LText.h"
#include "util.h"

using namespace std;

class Console
{
	public:
		Console(SDL_Renderer * _gRenderer);
		void draw();

	private:
		TTF_Font * font;
		SDL_Color textColor;
		stringstream newStream;
		SDL_Renderer * gRenderer;

		int lineWidth;
		int numberOfLines;
		int currentLine;

		char ** buffer;

		LTexture * texture;

		//Mthodes
		void updateBuffer();

		//Setter
		void SetConsole();
		//Getter

};

#endif // CONSOLE_H
