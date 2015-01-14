#ifndef OTGRENGINE_H
#define OTGRENGINE_H
#include "otgrapp.h"
#include "otgrsprite.h"
#include <list>

class OTGREngine : public OTGRApp{
private:
    std::list<OTGRSprite> sprites;
public:
    OTGREngine(unsigned int, unsigned int, const std::string &);
    ~OTGREngine();

    void onEvent();
    void onRender();

    /**
     * @brief insertSprite
     * @param sprite Sprite to be added
     */
    void insertSprite(OTGRSprite sprite);

};

#endif // OTGREngine_H
