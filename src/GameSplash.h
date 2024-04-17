#pragma once

#include <SDL2/SDL.h>
#include "engine/Engine.h"
#include "GameSplash.h"
#include "engine/scenes/SimpleScene.h"

class GameSplash: public SimpleScene{
public:
    /* CONSTRUTORES E DESTRUTORES */
    GameSplash();
    ~GameSplash();
};