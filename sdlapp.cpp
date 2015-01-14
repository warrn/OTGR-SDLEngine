#include "sdlapp.h"

SDLApp::SDLApp(unsigned int w, unsigned int h,const std::string &n = "Default Name"){
    window = NULL;
    renderer = NULL;
    window_w = w;
    window_h = h;
    name = n;
    quit = false;
    if(!this->onInit()) initialized = false;
    else initialized = true;

}

SDLApp::~SDLApp(){
    if(!this->onDestroy()) std::cerr << "Program failed to close!\n";
}

bool SDLApp::onInit(){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }
    else{
        //Create window
        window = SDL_CreateWindow( name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_w, window_h, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
            return false;
        }
        else{
            renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL){
                std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
                return false;
            }else{
                //Get window surface
                SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
                int IMGFLAG = IMG_INIT_PNG;
                if( !( IMG_Init( IMGFLAG ) & IMGFLAG ) ){
                    std::cerr << "SDL_Image failed. Error: " << IMG_GetError() << "\n";
                    return false;
                }
                return true;
            }
        }
    }
}

bool SDLApp::onDestroy(){
    // Destroy all SDL Surfaces
    for(std::map<std::string, SDL_Texture*>::iterator iter = textures.begin();
        iter != textures.end(); iter++){
        SDL_DestroyTexture(iter->second);
    }
    textures.clear();

    //Destroy renderer and window
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    renderer = NULL;
    window = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    return true;
}


bool SDLApp::loadImage(const std::string & name, const std::string & file){

    SDL_Texture *optimized = NULL;

    // Load initial surface
    SDL_Surface *image = IMG_Load(file.c_str());

    // Check if loaded
    if(image == NULL){
        std::cerr << "Image \"" << name << "\" failed to load, Error: "
                  << IMG_GetError() << "\n";
        return false;
    }else{
        // Make Texture
        optimized = SDL_CreateTextureFromSurface(renderer, image);

        // Free memory
        SDL_FreeSurface(image);

        if(optimized == NULL){
            std::cerr << "Optimization of image " << name << " failed, SDL Error: "
                      << SDL_GetError() << "\n";
            return false;
        }

        // Add to resources if successfully loaded
        textures[name] = optimized;
        return true;
    }
}

SDL_Texture* SDLApp::getResource(const std::string &name){
    // Grab resource from resources
    return textures[name];
}

