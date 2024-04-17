#include "Game.h"
#include "GameSplash.h"
#include "engine/scenes/SimpleScene.h"


/* CONSTRUTORES E DESTRUTORES */
Game::Game(int width, int height):Engine(width,height){
    
    // criação da tela de splash
    GameSplash* gameSplash = new GameSplash();
    this->sceneManager->startScene(gameSplash);

    gameloop(); //dispara o gameloop
}
Game::~Game(){}