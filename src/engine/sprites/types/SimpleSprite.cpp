#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------

SimpleSprite::SimpleSprite(std::string fileSource, int cx, int cy, int cw, int ch)
{
    this->img = this->loadTexture(fileSource);
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

SDL_Rect* SimpleSprite::getFrame() { return this->frames[0].get(0); }

SDL_Rect* SimpleSprite::getPos() {
    pos->x=posX;
    pos->y=posY;
    pos->w=this->cw;
    pos->h=this->ch;
    return pos;
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------

void SimpleSprite::init()
{
    initLinesList(1); // inicia a matriz de frames com apenas uma única linha (adequado para esta classe SimpleSprite)
    
    // obtem as dimensões da imagem carregada
    int width,height,access;
    unsigned int format;
    SDL_QueryTexture(this->img, &format, &access, &width, &height);

    if(this->cw == 0)       // se a largura do recorte não for passado...
        this->cw = width;   // é a da própria imagem
    if(this->ch == 0)       // se a altura do recorte não for passado...
        this->ch = height;   // é a da própria imagem

    // adiciona o único frame à única linha da matriz de frames
    for(int i=0;i < this->lineNumbers; i++){
        SDL_Rect* rect = new SDL_Rect();
        rect->x=cx; // origem x do corte da imagem
        rect->y=cy; // origem y do corte da imagem
        rect->w=cw; // largura do corte
        rect->h=ch; // altura do corte
        frames[i].add(rect);
    }
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------


void SimpleSprite::render() {
    SDL_RenderCopy(this->res->renderer, this->img, this->getFrame(),this->getPos());
}