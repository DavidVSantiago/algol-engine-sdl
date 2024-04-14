#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "../Resources.h"

/***********************************************************************************/
/* CLASSE ABSTRATA QUE REPRESENTA A BASE DAS CENAS */
/***********************************************************************************/
class Scene {
    
public:
    std::string name;
    Uint64 minTransitionTime;
    Resources* res;

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    Scene(std::string name);
    ~Scene();
    
    // GETTERS & SETTERS
    void setMinTransitionTime(Uint64 time);

    /* MÉTODOS DO GAMELOOP */
    virtual void handleEvents()=0;
    virtual void update()=0;
    virtual void render()=0;
};