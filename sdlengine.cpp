#include "sdlengine.h"

SDLEngine::SDLEngine(unsigned int w, unsigned int h, const std::string& n):
    SDLApp(w, h, n){

}

SDLEngine::~SDLEngine(){

}

void SDLEngine::onEvent(){
    // Make event container
    SDL_Event e;

    // Grab current event
    while(SDL_PollEvent(&e)){
        // Check if quit time
        if(e.type == SDL_QUIT){
            quit = true;
        }else if(e.type == SDL_KEYDOWN){
            quit = true;
        }
    }
}

void SDLEngine::onRender(){
    SDL_RenderClear(renderer);
    for(std::list<SDLSprite>::iterator iter = sprites.begin(); iter != sprites.end(); ++iter){
        SDL_Rect dstrect = iter->getCoordinates();
        SDL_RenderCopy(renderer, iter->getTexture(), NULL, &dstrect);
    }
    SDL_RenderPresent(renderer);
}

void SDLEngine::insertSprite(SDLSprite sprite){
    sprites.push_back(sprite);

}
