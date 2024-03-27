#ifndef ENGINE_H
#define ENGINE_H
// #include "Resources.h"
#include <SDL2/SDL.h>
#include "Resources.h"

class Engine
{
private:
    /* ATRIBUTOS PRIVADOS */
    Uint64 tempoAnterior, tempoAtual;
    Resources* res;

    /* MÉTODOS PRIVADOS */
    void checkEvents();

public:
    /* ATRIBUTOS */
    SDL_Window *window;
    SDL_Renderer *renderer;
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