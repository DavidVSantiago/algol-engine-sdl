#pragma once

#include <SDL2/SDL.h>

/** SINGLETON que gerencia o caregamento e transição entre as cenas do jogo
 * Classe usada pela maioria das outras classes da engine */
class Scene {
    
public:
    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    Scene();
    ~Scene();
    
    // GETTERS & SETTERS
    void setMinTransitionTime(Uint64 time);

    /* MÉTODOS */
    /** Invocado quando os recursos da cena começam a ser carregados */
    void onStartLoad(); // abstract
    /** Invocado após os recursos da cena serem todos carregados */
    void onFinishLoad(); // abstract
    /** Invocado quando a cena começa a ser exibida na tela */
    void onShow(); // abstract
    /** Inicializa todos os recursos assíncronos da cena, principalmente as imagens */
    //virtual void startLoadResources()=0; // abstract


    /* MÉTODOS DO GAMELOOP */
    void handleEvents();
    void update();
    void render();
}