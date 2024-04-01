#ifndef ENGINE_H
#define ENGINE_H
// #include "Resources.h"
#include <SDL2/SDL.h>
#include "Resources.h"
#include "sprites/types/SimpleSprite.h"
#include "sprites/Sprite.h"

class Engine
{
private:
    /* ATRIBUTOS PRIVADOS */
    Uint64 tempoAnterior, tempoAtual;
    Resources* res;
    SimpleSprite* sprite;

    /* MÉTODOS PRIVADOS */
    void checkEvents();

public:
    /* ATRIBUTOS */
    SDL_Event event;
    bool isRunning;

    /* CONSTRUTORES E DESTRUTORES */
    Engine(int width, int height);
    ~Engine();

    /* MÉTODOS DO GAMELOOP */
    void handleEvents();
    void update();
    void render();
    void gameloop();
};

#endif