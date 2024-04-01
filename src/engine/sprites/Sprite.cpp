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
    // cria a matriz com a quantidade de linhas definidas
    vector<vector<SDL_Rect>> frames(lineNumbers,vector<SDL_Rect>());
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 400;
    rect.h = 400;
    frames[0].push_back(rect);
}

