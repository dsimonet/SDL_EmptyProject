#include "Console.h"

Console::Console(SDL_Renderer * _gRenderer)
{
	lineWidth = 80;
	numberOfLines = 20;
	currentLine = 0;

	textColor = {0,0,0,0xFF};

    //change the underlying buffer and save the old buffer
    auto old_buf = cout.rdbuf(newStream.rdbuf());

	gRenderer = _gRenderer;
	font =	TTF_OpenFont( GetRelativePath("\\font\\consola.ttf"), 10 );
    texture = new LTexture(gRenderer, font);
    updateBuffer();
}

void Console::updateBuffer(){
	//buffer is a pointer to pointer to store address
	//of the dynamic allocated array
	//because it's a two dimensional array

    //We store in this pointer to pointer the address of the first address of an array address (tricky one)
    //all those address gonna point to part of memory who are an array of data
	buffer = new char*[numberOfLines];
	for(int i = 0; i < numberOfLines; i++){
		buffer[i] = new char[lineWidth];
		sprintf(buffer[i], "\n", i);
	}
}

void Console::draw(){
	if(newStream.str().c_str() == "" )
		return;
	else{
		currentLine++;
		currentLine %= numberOfLines;
	}

	buffer[currentLine] = const_cast<char*>( newStream.str().c_str() ) ;
	newStream.str("");

	for(int i = 0; i < numberOfLines; i++){
		int b =  (currentLine+i)%numberOfLines;
		texture->loadFromRenderedText(buffer[b], textColor);
		texture->render(10, 30+10*i);
	}

}
