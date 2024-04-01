#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------

SimpleSprite::SimpleSprite(char* fileSource, int cx, int cy, int cw, int ch)
{
    this->img = IMG_LoadTexture(Sprite::res->renderer, "braid-jump-teste.png");
    this->cx = cx;
    this->cy = cy;
    this->cw = cw;
    this->ch = ch;
    init();
}

SimpleSprite::~SimpleSprite()
{
}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------

SDL_Rect* SimpleSprite::getFrame()
{
  if(frames.size() > 0)
  // {
  //   // Validar se o índice 0 do primeiro elemento está dentro dos limites
  //   if (this->frames[0].size() > 0)
  //   {
  //     return &this->frames[0][0];
  //   }
  // }

  // // Se os índices forem inválidos, retorna nullptr
  return nullptr;
}
//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------

void SimpleSprite::init()
{
    initFramesList(1);
    // if(this->cw == 0)              // se a largura do recorte não for passado...
    //     this->cw = this.img.width;  // é a da própria imagem
    // if(this->ch == 0)              // se a altura do recorte não for passado...
    //     this.ch = this.img.height; // é a da própria imagem
}

bool SimpleSprite::checkEmptyImage(SDL_Surface *img, SDL_Rect cut)
{
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------


void SimpleSprite::render()
{
    SDL_RenderCopy(this->res->renderer, this->img, this->getFrame(),this->getFrame());
}