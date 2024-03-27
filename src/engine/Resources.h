#ifndef RESOURCES_H
#define RESOURCES_H
#include <SDL2/SDL.h>

class Resources
{
private:
    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    static Resources* instance; // singleton
    Resources(){}
    ~Resources(){}
public:
    /* ATRIBUTOS */
    long deltaTime;
    bool vk_up,vk_down,vk_left,vk_right;
    int screenWidth,screenHeigth;

    /* MÉTODOS */

    static Resources* getInstance(){
        if(instance==nullptr){
            instance=new Resources;
        }
        return instance;
    }   
    
    void init(int width, int height) {
        vk_up=vk_down=vk_left=vk_right=false;
        screenWidth=width;
        screenHeigth=height;
        deltaTime=0;
    }

    Uint64 getTimeTick(){
        return SDL_GetPerformanceCounter();
    }
};

#endif