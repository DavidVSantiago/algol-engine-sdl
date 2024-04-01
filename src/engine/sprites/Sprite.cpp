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
    frames = new SpriteList();
    for(int i=0;i<4;i++){
        SDL_Texture* obj = IMG_LoadTexture(Sprite::res->renderer, "braid-jump-teste.png");
        frames->add(obj);
    }

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 400;
    rect.h = 400;
    //frames[0]->push_back(rect);
}

