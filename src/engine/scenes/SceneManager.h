#pragma once

#include "Scene.h"
#include "LoadingScene.h"
#include "../Resources.h"

/** SINGLETON que gerencia o caregamento e transição entre as cenas do jogo
 * Classe usada pela maioria das outras classes da engine */
class SceneManager {
    
private:
    static SceneManager* instance; // singleton

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SceneManager(){}
    ~SceneManager(){}
    /* MÉTODOS PRIVADOS */
    void changeScene(Scene* scene);

public:
    Scene* actualScene;
    Scene* loadingScene;
    Resources* res;
    
    /* MÉTODOS */
    static SceneManager* getInstance();
    void init();/** Inicializa os recursos do SceneManager */
    
    void startScene(Scene* scene);

    void showLoadingScene();

    /* MÉTODOS DO GAMELOOP */
    void handleEvents();
    void update();
    void render();
};