#include "LoadingScene.h"

//---------------------------------------------------------------------------------------------------------
/* CONSTRUTORES E DESTRUTORES PRIVADOS*/
//---------------------------------------------------------------------------------------------------------
LoadingScene::LoadingScene(std::string name) : Scene(name) {
    this->loadingImage = new SimpleSprite("loading.png");
    this->loadingImage->posX=(this->res->screenWidth/2)-this->loadingImage->cw;
    this->loadingImage->posY=(this->res->screenHeigth/2)-this->loadingImage->ch;
}
LoadingScene::~LoadingScene(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------

void LoadingScene::handleEvents(){

}
void LoadingScene::update(){

}
void LoadingScene::render(){
    SDL_SetRenderDrawColor(this->res->renderer, 0, 0, 0, 255);
    this->loadingImage->render();
}
