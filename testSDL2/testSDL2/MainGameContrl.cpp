//
//  MainGameContrl.cpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/11.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#include "MainGameContrl.hpp"

typedef Singleton<CTextureManager> texManager;
typedef Singleton<EventManager> eventManeger;

MainGameContrl::MainGameContrl()
{
    
}

//void onEventCallBack()
//{
//    printf("onEventCallBack start");
//}

void MainGameContrl::InitGame(SDL_Renderer* mainRender)
{
    bgObj = new CTextureObj();
    SDL_Texture *backgroundImg = texManager::Instance()->LoadImage("UI_InGame_Background.png", mainRender);
    bgObj->tex = backgroundImg;
    
    srand( (unsigned int)time(NULL) );
    
    for( int i = 0 ; i < ALL_TILE_COLUMN_NUM ; i ++ )
    {
        for (int j = 0; j < ALL_TILE_ROW_NUM; j ++) {
            int randFruitIdx = rand() % 3 + 1;
            CTile *image = new CTile();
            SDL_Texture *itemImg = texManager::Instance()->LoadImage("fruit_" + std::to_string(randFruitIdx) + ".png", mainRender);
            image->texObj.tex = itemImg;
            image->position.first = INIT_TILE_POS_X + i*55;
            image->position.second = INIT_TILE_POS_Y + j*55;
            tiles.push_back(*image);
        }
       
    }
    
    //eventManeger::Instance()->RigisterEvent(eventManeger::Instance()->ON_MOUSE_CLICK, onEventCallBack);
    
}



void MainGameContrl::Render(SDL_Renderer* mainRender)
{
    texManager::Instance()->renderTexture(bgObj, mainRender, 0, 0);
    
    std::vector<CTile>::iterator it;
    for (it=tiles.begin(); it!=tiles.end(); ++it)
    {
        texManager::Instance()->renderTexture(&it->texObj, mainRender, it->position.first, it->position.second);
    }
    
}

void MainGameContrl::Loop()
{
    
}

void MainGameContrl::OnMouseClick(int x, int y)
{
    // check is any tile clicked
    CTile* tile = GetTouchTile(x,y);
    if( tile != nullptr)
    {
        printf("mouse click tile!");
    }
    
}

void MainGameContrl::OnMouseMotion(int x, int y)
{
    
}

void MainGameContrl::OnMouseUp(int x, int y)
{
    CTile* tile = GetTouchTile(x,y);
    if( tile != nullptr)
    {
        printf("mouse up tile!");
    }
}

CTile* MainGameContrl::GetTouchTile(int mX, int mY)
{
    for (int i = 0 ; i < tiles.size(); i ++ ) {
        CTile tile = tiles[i];
        if( mX >= tile.position.first && mX <= tile.position.first + tile.texObj.width &&
           mY >= tile.position.second && mY <= tile.position.second + tile.texObj.height )
        {
            return &tiles[i];
        }
    }
    
    return nullptr;
}

