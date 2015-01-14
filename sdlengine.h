#ifndef SDLENGINE_H
#define SDLENGINE_H
#include "sdlapp.h"
#include "sdlsprite.h"
#include <list>

class SDLEngine : public SDLApp{
private:
    std::list<SDLSprite> sprites;
public:
    SDLEngine(unsigned int, unsigned int, const std::string &);
    ~SDLEngine();

    void onEvent();
    void onRender();

    /**
     * @brief insertSprite
     * @param sprite Sprite to be added
     */
    void insertSprite(SDLSprite sprite);

};

#endif // SDLENGINE_H
