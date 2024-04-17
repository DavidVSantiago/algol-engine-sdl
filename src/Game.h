#pragma once

#include <SDL2/SDL.h>
#include "engine/Engine.h"

class Game: public Engine{
public:
    /* CONSTRUTORES E DESTRUTORES */
    Game(int width, int height);
    ~Game();
};