#pragma once
// #include "Resources.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../utils/estruturas_de_dados.h"
#include "../Resources.h"

using namespace std;

/** Implementação abstrata de um Sprite.
 * Elementos básicos de todos os tipos de Sprites. */
class Sprite
{
public:
    /* ATRIBUTOS ------------------------------------------------------------------*/
    ListaEstatica<SDL_Rect*>*frames; // matriz de frames do sprite
    int lineNumbers; // numero de linhas da matriz de frames
    int posX;
    int posY;
    SDL_Rect* pos;
    int speedX;
    int speedY;
    bool loaded;
    Resources *res;

    /* CONSTRUTORES E DESTRUTORES -------------------------------------------------*/
    Sprite();
    ~Sprite();

    /* GETTERS & SETTERS ----------------------------------------------------------*/

    /** Retorna o frame correto para a renderização. */
    virtual SDL_Rect *getFrame() = 0; // abstract

    /** Retorna a posição correta para a renderização na tela. */
    virtual SDL_Rect *getPos()=0;

    /* MÉTODOS --------------------------------------------------------------------*/

    /** Invocado após os recursos da imagem serem todos carregados */
    virtual void init() = 0; // abstract

    /** Inicializa o o array de frames do sprite
     * @param {Number} lineNumbers numero de linhas no array (cada linha é um sprite) */
    void initLinesList(int lineNumbers);

    /** carrega um textura no arquivo */
    SDL_Texture* loadTexture(std::string fileSource);

    /* MÉTODOS DO GAMELOOP --------------------------------------------------------*/

    virtual void render()=0; // abstract
};