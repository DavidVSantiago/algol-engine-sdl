#include "GameSplash.h"
#include "engine/scenes/SimpleScene.h"
#include "engine/scenes/SceneManager.h"


/* CONSTRUTORES E DESTRUTORES */
GameSplash::GameSplash():SimpleScene("SPLASH"){
    // criação da tela de splash
    Sprite* fundo = new SimpleSprite("splash.png");
    this->registrarSprite(fundo,0);
}
GameSplash::~GameSplash(){}