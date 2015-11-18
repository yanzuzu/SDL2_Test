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
    tiles = new CTile*[ALL_TILE_ROW_NUM];
    for (int i = 0 ; i < ALL_TILE_ROW_NUM; i ++) {
        tiles[i] = new CTile[ALL_TILE_COLUMN_NUM];
    }
}

void OnMouseClickEventCallBack(void *args)
{
    EventMouseClickData data = *( ( EventMouseClickData* )args );
    printf("onEventCallBack start x = %d , y = %d \n" , data.mX, data.mY);
}

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
            tiles[i][j] = *image;
        }
       
    }
    eventManeger::Instance()->RigisterEvent(eventManeger::Instance()->ON_MOUSE_CLICK, OnMouseClickEventCallBack);
    
}



void MainGameContrl::Render(SDL_Renderer* mainRender)
{
    texManager::Instance()->renderTexture(bgObj, mainRender, 0, 0);
    
    for (int i = 0; i < ALL_TILE_COLUMN_NUM; i ++ ) {
        for ( int j = 0 ;  j < ALL_TILE_ROW_NUM; j ++ ) {
             texManager::Instance()->renderTexture( &tiles[i][j].texObj, mainRender, tiles[i][j].position.first, tiles[i][j].position.second);
        }
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
        currentClickTile = tile;
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
        if( currentClickTile != nullptr)
        {
            int tmpX = tile->position.first;
            int TmpY = tile->position.second;
            
            tile->position.first = currentClickTile->position.first;
            tile->position.second = currentClickTile->position.second;
            
            currentClickTile->position.first = tmpX;
            currentClickTile->position.second = TmpY;
            
        }

    }
}

CTile* MainGameContrl::GetTouchTile(int mX, int mY)
{
    for (int i = 0; i < ALL_TILE_COLUMN_NUM; i ++ ) {
        for ( int j = 0 ;  j < ALL_TILE_ROW_NUM; j ++ ) {
            CTile tile = tiles[i][j];
            if( mX >= tile.position.first && mX <= tile.position.first + tile.texObj.width &&
               mY >= tile.position.second && mY <= tile.position.second + tile.texObj.height )
            {
                return &tiles[i][j];
            }
        
        }
    }
    
    return nullptr;
}

