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
private:
    int layersSize = 10; // quantidade padrão de layers de uma cena

    
public:
    /* ATRIBUTOS DE TRANSIÇÃO DE TELA*/
    Uint32 elapsedTime;
    Uint32 fadeDurationTime;
    Uint32 minTransitionTime;
    // tela preta para a transição
    SimpleSprite* blackScreen;

    SceneLayer** sceneLayersList; // lista de layers da cena

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SimpleScene(std::string name);
    ~SimpleScene();
    
    /* MÉTODOS */
    void registrarSprite(Sprite* sprite, int layerIndex);

    /* MÉTODOS DO GAMELOOP */
    void render() override;
    void handleEvents() override;
    void update() override;
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