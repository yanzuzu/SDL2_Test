//
//  CApp.cpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/6.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//
#include "CApp.hpp"
#include <SDL2_image/SDL_image.h>
#include "Singleton.h"
using namespace std;

typedef Singleton<EventManager> eventManeger;
typedef Singleton<MainGameContrl> mainGameCtrl;

CApp::CApp() {
    mainWin = NULL;
    Running = true;
}

void CApp::OnCleanup() {
    //Clean up our objects and quit
    SDL_DestroyRenderer(mainRen);
    SDL_DestroyWindow(mainWin);
    SDL_Quit();
}

void CApp::OnRender() {
    
    SDL_RenderClear(mainRen);
    mainGameCtrl::Instance()->Render(mainRen);
    // Text
//    CText text;
//    SDL_Color color = { 255, 255, 255, 255 };
//    SDL_Texture *fontImg = text.renderText("TTF fonts are cool!",  "OpenSans-Regular.ttf",
//                                    color, 64, mainRen);
//    CTextureObj fontObj;
//    fontObj.tex = fontImg;
//    texManager::Instance()->renderTexture(&fontObj, mainRen, 0, 0);
    
    
    SDL_RenderPresent(mainRen);

}


void CApp::OnLoop() {
    mainGameCtrl::Instance()->Loop();
}

void CApp::OnEvent(SDL_Event* Event) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }else if (Event->type == SDL_MOUSEMOTION)
    {
        mainGameCtrl::Instance()->OnMouseMotion( Event->motion.x,Event->motion.y);
    }else if( Event->type == SDL_MOUSEBUTTONDOWN)
    {
        int mX,mY = 0;
        SDL_GetMouseState(&mX, &mY);
        eventManeger::Instance()->FireEvent(eventManeger::Instance()->ON_MOUSE_CLICK);
        mainGameCtrl::Instance()->OnMouseClick(mX, mY);
    }else if( Event->type == SDL_MOUSEBUTTONUP)
    {
        int mX,mY = 0;
        SDL_GetMouseState(&mX, &mY);
        mainGameCtrl::Instance()->OnMouseUp(mX, mY);
    }
}

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    
    mainWin = SDL_CreateWindow("Hello World", 0, 0, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (mainWin == nullptr){
        SDL_Quit();
        return false;
    }
    mainRen = SDL_CreateRenderer(mainWin, -1,
                                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mainRen == nullptr){
        SDL_Quit();
        return false;
    }
    
    if (TTF_Init() != 0){
        SDL_Quit();
        return false;
    }
    
    mainGameCtrl::Instance()->InitGame(mainRen);
    //e::Instance()->RigisterEvent();
    return true;
}
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
    
    SDL_Event Event;
    
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        
        OnLoop();
        OnRender();
    }
    
    OnCleanup();
    
    return 0;
}

int main(int argc, char* argv[]) {
    CApp theApp;
    
    return theApp.OnExecute();
}