#pragma once

#include <SDL2/SDL.h>
#include "Scene.h"
#include "../sprites/types/SimpleSprite.h"


class LoadingScene : public Scene {
    
public:
    SimpleSprite* loadingImage;

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    LoadingScene(std::string name);
    ~LoadingScene();
    
    // GETTERS & SETTERS

    /* MÉTODOS DO GAMELOOP */
    void handleEvents() override;
    void update() override;
    void render() override;
};