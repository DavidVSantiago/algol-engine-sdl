#include "Scene.h"

//---------------------------------------------------------------------------------------------------------
/* CONSTRUTORES E DESTRUTORES PRIVADOS*/
//---------------------------------------------------------------------------------------------------------
Scene::Scene(std::string name){
    this->name = name; // toda Scene possui um nome associado a ela
    this->res = Resources::getInstance();
}
Scene::~Scene(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
void Scene::setMinTransitionTime(Uint64 time){
    this->minTransitionTime=time;
}
