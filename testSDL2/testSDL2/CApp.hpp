//
//  CApp.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/6.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef _CAPP_H_
#define _CAPP_H_

#include "CTextureManager.hpp"
#include "EventManager.hpp"
#include "CText.hpp"
#include "MainGameContrl.hpp"
#include <SDL2/SDL.h>

class CApp {
private:
    bool    Running;
    const int SCREEN_WIDTH  = 480;
    const int SCREEN_HEIGHT = 640;
    SDL_Window*    mainWin;
    SDL_Renderer* mainRen;
public:
    CApp();
    
    int OnExecute();
    
public:
    
    bool OnInit();
    
    void OnEvent(SDL_Event* Event);
    
    void OnLoop();
    
    void OnRender();
    
    void OnCleanup();
};

#endif
