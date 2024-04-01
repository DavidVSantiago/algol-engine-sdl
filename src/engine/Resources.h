#pragma once

#include <SDL2/SDL.h>

class Resources
{
private:
    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    static Resources* instance; // singleton
    Resources(){}
    ~Resources(){}
public:

    /* ATRIBUTOS */
    long deltaTime;
    bool vk_up,vk_down,vk_left,vk_right;
    int screenWidth,screenHeigth;
    SDL_Window *window;
    SDL_Renderer *renderer;

    /* MÉTODOS */
    static Resources* getInstance();
    void init(int width, int height);
    Uint64 getTimeTick();
};