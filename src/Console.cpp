#include "Console.h"

Console::Console(SDL_Renderer * _gRenderer) {
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

void Console::pushLine() {
    currentLine++;
    currentLine %= numberOfLines;
}

void Console::updateBuffer() {
    //buffer is a pointer to pointer to store address
    //of the dynamic allocated array
    //because it's a two dimensional array

    //We store in this pointer to pointer the address of the first address of an array address (tricky one)
    //all those address gonna point to part of memory who are an array of data
//    buffer = new char*[numberOfLines];
//    for(int i = 0; i < numberOfLines; i++) {
//        buffer[i] = new char[lineWidth];
//        sprintf(buffer[i], "", i);
//    }
	for(int i = 0; i < numberOfLines; i++){
		buffer.push_back("");
		}
}

void Console::draw() {
    //catch last input
    string str = newStream.str();
    if(str == "")
        return;

    string::size_type pos = 0;
    string::size_type prev = 0;
    while ((pos = str.find('\n', prev)) != string::npos) {
		buffer[currentLine] = "";
		if(pos > prev){
			buffer[currentLine] =  const_cast<char*>( str.substr(prev, pos - prev).c_str() );
		}else{
			buffer[currentLine] = "";
		}
        prev = pos + 1;
		pushLine();
    }

    // To get the last substring (or only, if delimiter is not found)
    buffer[currentLine] = const_cast<char*>( str.substr(prev).c_str() );
    pushLine();

    //clear last input
    newStream.str("");

    //printing console buffer
    for(int i = 0; i < numberOfLines; i++) {
        int b =  (currentLine+i)%numberOfLines;
			if(buffer.at(b) != "" ){
				texture->loadFromRenderedText(buffer.at(b), textColor);
				texture->render(10, 30+10*i);
			}
    }

}
