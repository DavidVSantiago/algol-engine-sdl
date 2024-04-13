#include "Sprite.h"

#include <cmath>

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------

Sprite::Sprite()
{
    posX = 0.0;
    posY = 0.0;
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

void Sprite::initFramesList(int lineNumbers)
{
    // cria a matriz de sprites com a quantidade de linhas definidas
    frames = new SpriteList[lineNumbers];
    for(int i=0;i<lineNumbers;i++){
        SDL_Rect* rect = new SDL_Rect();
        rect->x=rect->y=0;
        rect->w=400;
        rect->h=350;
        frames[i].add(rect);
    }
}

SDL_Texture* Sprite::loadTexture(std::string path) {
    // The final texture
    SDL_Texture *newTexture = NULL;
    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(res->renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

