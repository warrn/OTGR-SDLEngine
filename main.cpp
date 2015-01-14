#include "sdlengine.h"

// Constants
const unsigned int SCREEN_WIDTH = 1200;
const unsigned int SCREEN_HEIGHT = 800;
const std::string APPNAME = "SDL Engine";
const std::string hello = "/home/wing/Projects/C++/SDLTest/hello_world.bmp";

int main( int argc, char* args[] ){
    SDLEngine a(SCREEN_WIDTH, SCREEN_HEIGHT, APPNAME);
    a.loadImage("hello",hello);

    SDLSprite sprite(a.getResource("hello"),320,240,320,240);
    a.insertSprite(sprite);
    while(!a.isQuit()){
        a.onEvent();
        a.onRender();
    }
    return 0;

}
