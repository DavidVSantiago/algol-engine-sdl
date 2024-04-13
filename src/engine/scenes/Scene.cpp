#include "Scene.h"

//---------------------------------------------------------------------------------------------------------
/* CONSTRUTORES E DESTRUTORES PRIVADOS*/
//---------------------------------------------------------------------------------------------------------
Scene::Scene(String nome){
    String nome = nome; // toda Scene possui um nome associado a ela
    Resources res = Resources.getInstance(); // ref. para o singleton de recursos
    this.urlList = []; // lista dos caminhos todas as as imagens da cena
    
    // cria um sprite procedural para representar um fundo preto (comum a várias cenas)
    this.blackScreen = new OffscreenCanvas(this.res.canvas.width, this.res.canvas.height);
    this.blackScreenCtx = this.blackScreen.getContext('2d');
    this.blackScreenCtx.fillStyle = "black";
    this.blackScreenCtx.globalAlpha = 1; // tela preta da transição opaca
    this.blackScreenCtx.fillRect(0, 0, this.blackScreen.width, this.blackScreen.height);
    this.black = new SimpleProcSprite(this.blackScreen);  
}
~Scene::Scene(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
void Scene::setMinTransitionTime(Uint64 time){

}

//---------------------------------------------------------------------------------------------------------
/* MÉTODOS */
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
/* MÉTODOS DO GAMELOOP */
//---------------------------------------------------------------------------------------------------------
void Scene::handleEvents(){

}
void Scene::update(){

}
void Scene::render(){

}
