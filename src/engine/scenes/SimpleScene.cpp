#include "SimpleScene.h"

//---------------------------------------------------------------------------------------------------------
/* CONSTRUTORES E DESTRUTORES PRIVADOS*/
//---------------------------------------------------------------------------------------------------------
SimpleScene::SimpleScene(std::string name):Scene(name){
    elapsedTime=0; // tempo decorrido da cena
    fadeDurationTime=500; // tempo que dura um fade de transição de uma cena (metade da transição completa)
    
    /* inicializa o a lista de layers da cena */
    sceneLayersList = new SceneLayer*[layersSize];
    for(int i=0;i<layersSize;i++){
        sceneLayersList[i]=new SceneLayer();
    }
    for(int i=0;i<1000000000;i++){
        int v1=10;
        int v2=300;
        int v3=20;
        int v4 = v1/v2;
        int v5=(v4/v3)*v1;
    }
}
SimpleScene::~SimpleScene(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------
void SimpleScene::registrarSprite(Sprite* sprite, int layerIndex){
    this->sceneLayersList[layerIndex]->putSprite(sprite);
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------

/** renderiza todos os layers da cena */
void SimpleScene::render(){
    for(int i=0;i<layersSize;i++){
        sceneLayersList[i]->render();
    }
}

void SimpleScene::handleEvents(){

}

void SimpleScene::update(){

}