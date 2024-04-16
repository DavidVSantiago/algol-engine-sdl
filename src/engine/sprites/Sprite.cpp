#include "Sprite.h"

#include <cmath>

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------

Sprite::Sprite()
{
    posX = 0.0;
    posY = 0.0;
    pos = new SDL_Rect();
    speedX = 0.0;
    speedY = 0.0;
    loaded = false;
    res = Resources::getInstance();
}
Sprite::~Sprite()
{
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------

void Sprite::initLinesList(int lineNumbers)
{
    this->lineNumbers=lineNumbers;
    // cria a matriz de sprites com a quantidade de linhas definidas
    frames = new ListaEstatica<SDL_Rect*>[lineNumbers];
}

SDL_Texture* Sprite::loadTexture(std::string fileSource) {
    std::string source = Resources::PATH_IMGS_ASSETS+fileSource;
    // The final texture
    SDL_Texture *newTexture = NULL;
    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(source.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", source.c_str(), IMG_GetError());
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(res->renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", source.c_str(), SDL_GetError());
        }
        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

