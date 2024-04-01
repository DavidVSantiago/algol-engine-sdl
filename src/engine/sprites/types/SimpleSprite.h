#ifndef SIMPLE_SPRITE_H
#define SIMPLE_SPRITE_H

#include "../Sprite.h"
#include "SDL2/SDL_image.h"

using namespace std;

/** Implementação mais simples de Sprite de arquivos de imagem.
 * Para sprites com apenas um único frame. */
class SimpleSprite : public Sprite
{
public:
    /* ATRIBUTOS ------------------------------------------------------------------*/
    SDL_Texture* img;
    int cx, cy; // coordenadas do ponto de corte da imagem
    int cw, ch; // dimensões do recorte da imagem

    /* CONSTRUTORES E DESTRUTORES -------------------------------------------------*/
    SimpleSprite(char* fileSource, int cx = 0, int cy = 0, int cw = 0, int ch = 0);
    ~SimpleSprite();
   
    /* GETTERS & SETTERS ----------------------------------------------------------*/

    /** Retorna o frame único do sprite para a renderização. */
    SDL_Rect* getFrame() override;

    /* MÉTODOS --------------------------------------------------------------------*/
    
    /** Inicializa o processamento de recorte dos frames do sprite
    * só pode ser invocada após a imagem ser totalmente carregada (Image.onload) */
    void init() override;

    /** Verifica se a imagem está vazia (com todos os pixels transparentes) */
    bool checkEmptyImage(SDL_Surface* img, SDL_Rect cut);

    /* MÉTODOS DO GAMELOOP --------------------------------------------------------*/

    void render();
};

#endif