#pragma once
#include "SDL2/SDL.h"

/** Uma lista de SDL_Texture, otimizada para operações de busca*/
class SpriteList{
    private:
    typedef SDL_Texture* DATA;
    //---------------------------------------------------------------------------------------------------------
    // ATRIBUTOS PRIVADOS
    //---------------------------------------------------------------------------------------------------------
    int capacidade=5; // capacidade padrão
    int aumento=5; // qtd de aumento da capacidade na operação "aumentarCapacidadeCasoNecessario()"
    int qtd;
    DATA* dados; // um array de DATA

    //---------------------------------------------------------------------------------------------------------
    // MÉTODOS PRIVADOS
    //---------------------------------------------------------------------------------------------------------
    void aumentarCapacidadeCasoNecessario();

    public:
    //---------------------------------------------------------------------------------------------------------
    // CONTRUTORES
    //---------------------------------------------------------------------------------------------------------
    SpriteList();

    //---------------------------------------------------------------------------------------------------------
    // MÉTODOS
    //---------------------------------------------------------------------------------------------------------
    int capacity(); // retorna a capacidade máxima de elementos
    int size(); // retorna a qtd de elementos atualmente existentes
    int add(DATA valor); // adiciona no início
    int add(DATA valor, int index); // adiciona em um índice específico
    DATA get(int index); // obtém um valor de uma posição específicia
    void remove(int index); // remove de uma posição específica
};