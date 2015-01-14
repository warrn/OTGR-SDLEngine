#include "sdlsprite.h"

SDLSprite::SDLSprite(SDL_Texture *t, int w, int h, int x_coordinate, int y_coordinate, int rotation):
    texture(t), width(w), height(h), x(x_coordinate), y(y_coordinate), r(rotation) {
}

SDLSprite::~SDLSprite(){

}

SDL_Rect SDLSprite::getCoordinates() const{
    SDL_Rect r;
    r.h = height;
    r.w = width;
    r.x = x;
    r.y = y;
    return r;

}

void SDLSprite::setCoordinate(int x_coordinate, int y_coordinate){
    x = x_coordinate;
    y = y_coordinate;
}
