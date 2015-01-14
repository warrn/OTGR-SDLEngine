#ifndef SDLAPP_H
#define SDLAPP_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>
#include <iostream>

class SDLApp{
protected:
    unsigned int window_w, window_h;
    std::string name;

    // The window + renderer for the app
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Resources container
    std::map<std::string, SDL_Texture*> textures;
    std::map<std::string, SDL_Rect> texture_size;

    // Initialize check
    bool initialized, quit;

    // Stages
    bool onInit();
    bool onDestroy();

public:
    // Constructor
    SDLApp(unsigned int, unsigned int, const std::string&);
    // Destructor
    ~SDLApp();
    bool isQuit() const { return quit; }



    // Member Functions

    /**
     * @brief loadBMP Loads a SDL_Surface from a .BMP file
     * @param name Name to associate with resource in the container map
     * @param file Full filename to .BMP image
     * @return True if successful load, False if problem loading
     */
    bool loadImage(const std::string & name , const std::string & file);

    /**
     * @brief getResource Get pointer to resource from resource container
     * @param name Name associated with resource in the container map
     * @return SDL_Surface pointer of the resource
     */
    SDL_Texture* getResource(const std::string & name);


};



#endif // SDLAPP_H
