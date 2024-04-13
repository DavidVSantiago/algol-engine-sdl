#include "SceneManager.h"

SceneManager *SceneManager::instance = nullptr; // inicialização da instância (específico do C++)

//---------------------------------------------------------------------------------------------------------
/* MÉTODOS PRIVADOS */
//---------------------------------------------------------------------------------------------------------

void SceneManager::changeScene(Scene* scene){
    this->actualScene=scene;
}

//---------------------------------------------------------------------------------------------------------
/* MÉTODOS */
//---------------------------------------------------------------------------------------------------------

SceneManager* SceneManager::getInstance(){
    if (instance == nullptr) {
        instance = new SceneManager();
    }   
    return instance;
}
void SceneManager::init(){
    this->loadingScene = new LoadingScene("LOADING"); // cena usada entre os carregamentos das cenas
    this->changeScene(this->loadingScene); // cena atual será essa
}
void SceneManager::startScene(Scene* scene){
    this->changeScene(scene);
}

//---------------------------------------------------------------------------------------------------------
/* MÉTODOS DO GAMELOOP */
//---------------------------------------------------------------------------------------------------------

void SceneManager::handleEvents(){
    this->actualScene->handleEvents();
}
void SceneManager::update(){
    this->actualScene->update();
}
void SceneManager::render(){
    this->actualScene->render();
}