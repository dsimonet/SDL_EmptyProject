#include "util.h"

using namespace std;

string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}


char * GetRelativePath( const char * _in){

    string cwd = ExePath();
    char * buffer = new char [MAX_PATH];

    strncpy (buffer, cwd.c_str(), MAX_PATH);
    return strcat(buffer,  _in);

}


SDL_Texture * loadTexture(SDL_Renderer * _renderer, string path ) {
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s \n\r", path.c_str(), IMG_GetError() );
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( _renderer, loadedSurface );
        if( newTexture == NULL ) {
            printf( "Unable to create texture from %s! SDL Error: %s\n\r", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void printHere(SDL_Renderer * gRenderer, char * t, int posX, int posY){
	SDL_Color c = {0,0,0, 0xff} ;

	std::stringstream infoText;
	infoText.str("");
	infoText << t ;
	TTF_Font * gFont;
	gFont = TTF_OpenFont(GetRelativePath("\\font\\consola.ttf"), 12 );
	LTexture tex(gRenderer, gFont);
	tex.loadFromRenderedText(infoText.str().c_str(), c);
	tex.render(20, 20);
}

