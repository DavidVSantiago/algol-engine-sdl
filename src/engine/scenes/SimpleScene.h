#pragma once

#include <SDL2/SDL.h>
#include "Scene.h"
#include "../sprites/types/SimpleSprite.h"
#include "../utils/estruturas_de_dados.h"

class SceneLayer; // declaração antecipada

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CENA SIMPLES */
/***********************************************************************************/
class SimpleScene : public Scene {
    
public:
    /* ATRIBUTOS DE TRANSIÇÃO DE TELA*/
    Uint32 elapsedTime;
    Uint32 transitionDurationTime;
    Uint32 minTransitionTime;

    ListaEstatica<SceneLayer*>* sceneLayersList; // lista de layers da cena

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SimpleScene(std::string name);
    ~SimpleScene();
    
    // GETTERS & SETTERS

    /* MÉTODOS DO GAMELOOP */
};

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CAMADA DE SPRITES A SER INCORPORADA NA CENA */
/***********************************************************************************/

class SceneLayer{
public:
    /* ATRIBUTOS DE TRANSIÇÃO DE TELA */
    ListaEstatica<Sprite*>* spritesList; // lista de sprites do Layer
    Resources* res;

    /* CONSTRUTORES E DESTRUTORES PRIVADOS */
    SceneLayer(){
        spritesList = new ListaEstatica<Sprite*>(); // pilha de sprites renderizaveis
        res = Resources::getInstance();
    }
    ~SceneLayer(){}
    
    //---------------------------------------------------------------------------------------------------------
    // MÉTODOS
    //---------------------------------------------------------------------------------------------------------

    void putSprite(Sprite* sprite){
        spritesList->add(sprite);
    }
    Sprite* getSprite(int index){
        return spritesList->get(index);
    }

    //---------------------------------------------------------------------------------------------------------
    // MÉTODOS DO GAMELOOP
    //---------------------------------------------------------------------------------------------------------

    void render(){
        // renderiza todos os sprites desse layer
        for(int i=0;i<spritesList->size();i++){
            spritesList->get(i)->render();
        }
    }
};