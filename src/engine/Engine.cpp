#include "Engine.h"
#include "scenes/SimpleScene.h"
#include <stdio.h>

/*****************************************************************************/
/* CONSTRUTORES E DESTRUTORES */
/*****************************************************************************/

Engine::Engine(int width, int height)
{

    // inicializa o SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    this->isRunning = true;

    // inicializa o Resources
    this->res = Resources::getInstance();
    this->res->init(width, height);

    // inicializa o SceneManager
    this->sceneManager = SceneManager::getInstance();
    this->sceneManager->init();

    // TODO este código deve ser levado para a classe que herda de Engine
    SimpleScene* cenaSplash = new SimpleScene("SPLASH");
    Sprite* fundo = new SimpleSprite("splash.png");
    cenaSplash->registrarSprite(fundo,0);
    this->sceneManager->startScene(cenaSplash);

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
    this->sceneManager->render();
    SDL_RenderPresent(this->res->renderer);
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