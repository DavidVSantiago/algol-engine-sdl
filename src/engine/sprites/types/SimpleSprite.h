#pragma once

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
    SimpleSprite(std::string fileSource, int cx = 0, int cy = 0, int cw = 0, int ch = 0);
    ~SimpleSprite();
   
    /* GETTERS & SETTERS ----------------------------------------------------------*/

    /** Retorna o frame único do sprite para a renderização. */
    SDL_Rect* getFrame() override;

    /** Retorna a posição correta para a renderização na tela. */
    SDL_Rect* getPos() override; // abstract

    /* MÉTODOS --------------------------------------------------------------------*/
    
    /** Inicializa o processamento de recorte dos frames do sprite
    * só pode ser invocada após a imagem ser totalmente carregada (Image.onload) */
    void init() override;

    /* MÉTODOS DO GAMELOOP --------------------------------------------------------*/

    void render() override;
};