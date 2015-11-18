//
//  MainGameContrl.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/11.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef MainGameContrl_hpp
#define MainGameContrl_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "CTextureManager.hpp"
#include "EventManager.hpp"
#include "Singleton.h"
#include "CTile.hpp"

class MainGameContrl
{
private:
    const int ALL_TILE_COLUMN_NUM = 5;
    const int ALL_TILE_ROW_NUM = 4;
    
    const int INIT_TILE_POS_X = 10;
    const int INIT_TILE_POS_Y = 250;
    
    CTile *currentClickTile;
    CTile *exchangeTile;
    
    CTile* GetTouchTile(int mX, int mY);
    
public:
    MainGameContrl();
    CTextureObj *bgObj;
    CTile** tiles;
public:
    void InitGame(SDL_Renderer* mainRender);
    void Render(SDL_Renderer* mainRender);
    void Loop();
    
    // mouse event
    void OnMouseClick(int x, int y);
    void OnMouseMotion(int x, int y);
    void OnMouseUp(int x, int y);
    
};
#endif /* MainGameContrl_hpp */
