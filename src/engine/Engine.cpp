#include "Engine.h"

/*****************************************************************************/
/* CONSTRUTORES E DESTRUTORES */
/*****************************************************************************/

Engine::Engine(int width, int height)
{

    // inicializa o SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    this->isRunning = true;

    // inicializa o Resources
    this->res = Resources::getInstance();;
    this->res->init(width, height);
    sprite = new SimpleSprite("braid-jump-teste.png");

    // inicializa o SceneManager

    // eventos de pressionamentos e soltura das teclas
    // dispara o gameloop
    gameloop();
}

Engine::~Engine()
{
}

/*****************************************************************************/
/* MÉTODOS DO GAMELOOP */
/*****************************************************************************/

void Engine::handleEvents()
{
}

void Engine::update()
{
}

void Engine::render()
{
    SDL_RenderClear(this->res->renderer);
    SDL_SetRenderDrawColor(this->res->renderer, 255, 0, 0, 255);
    sprite->render();
    SDL_RenderPresent(this->res->renderer);
    //std::cout << this->res->deltaTime;
}

void Engine::gameloop()
{
    while (isRunning)
    {
        checkEvents(); // trata os eventos

        this->tempoAtual = this->res->getTimeTick();
        this->res->deltaTime = (this->tempoAtual - this->tempoAnterior);

        this->handleEvents();
        this->update();
        this->render();

        this->tempoAnterior = this->tempoAtual; // atualiza o tempo anterior (para o próximo quadro)
    }
    SDL_DestroyRenderer(this->res->renderer);
    SDL_DestroyWindow(this->res->window);
    SDL_Quit();
}

void Engine::checkEvents() {
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
        }
    }
}