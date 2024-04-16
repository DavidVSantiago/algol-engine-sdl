#include "Resources.h"

//---------------------------------------------------------------------------------------------------------
// DEFINIÇÃO DOS ATRIBUTOS ESTÁTICOS
//---------------------------------------------------------------------------------------------------------
Resources *Resources::instance = nullptr; // inicialização da instância (específico do C++)
std::string Resources::PATH_IMGS_ASSETS = "src/assets/imgs/";

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------

Resources* Resources::getInstance()
{
    if (instance == nullptr) {
        instance = new Resources;
    }
    return instance;
}

void Resources::init(int width, int height)
{
    vk_up = vk_down = vk_left = vk_right = false;
    screenWidth = width;
    screenHeigth = height;
    deltaTime = 0;
    window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

Uint64 Resources::getTimeTick()
{
    return SDL_GetPerformanceCounter();
}