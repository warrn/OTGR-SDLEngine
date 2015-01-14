#include "otgrengine.h"

OTGREngine::OTGREngine(unsigned int w, unsigned int h, const std::string& n):
    OTGRApp(w, h, n){

}

OTGREngine::~OTGREngine(){

}

void OTGREngine::onEvent(){
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

void OTGREngine::onRender(){
    SDL_RenderClear(renderer);
    for(std::list<OTGRSprite>::iterator iter = sprites.begin(); iter != sprites.end(); ++iter){
        SDL_Rect dstrect = iter->getCoordinates();
        SDL_RenderCopy(renderer, iter->getTexture(), NULL, &dstrect);
    }
    SDL_RenderPresent(renderer);
}

void OTGREngine::insertSprite(OTGRSprite sprite){
    sprites.push_back(sprite);

}
