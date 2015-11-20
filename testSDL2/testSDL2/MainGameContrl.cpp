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

MainGameContrl::~MainGameContrl()
{
}


void OnMouseClickEventCallBack(void *args)
{
    EventMouseClickData data = *( ( EventMouseClickData* )args );
    printf("onEventCallBack start x = %d , y = %d \n" , data.mX, data.mY);
}

void MainGameContrl::CaculateConnect()
{
    for (int i = 0 ; i < ALL_TILE_COLUMN_NUM; i ++ ) {
        for (int j = 0 ; j < ALL_TILE_ROW_NUM; j ++) {
            CheckConnect(i,j, i + 1 , ALL_TILE_COLUMN_NUM , j , j + 1 );
            CheckConnect(i,j, i , i + 1 , j + 1 , ALL_TILE_ROW_NUM );
        }
    }
}

void MainGameContrl::CheckConnect(int pX, int pY, int pFromX, int pEndX , int pFromY, int pEndY)
{
    CTile *origiTile = GetTileByPos(pX, pY);
    std::vector<CTile*> connectTiles;
    bool isDisConnect = false;
    for( int i = pFromX ; i < pEndX  ; i ++ )
    {
        if (isDisConnect) {
            break;
        }
        for (int j = pFromY; j < pEndY; j ++ ) {
            CTile *tile = GetTileByPos(i,j);
            if( tile == nullptr || origiTile->isEliminate == true )
            {
                continue;
            }
            if( tile->GetType() == origiTile ->GetType() && tile->isEliminate == false )
            {
                connectTiles.push_back(tile);
            }else
            {
                isDisConnect = true;
                break;
            }

        }
    }
    //printf("connect tile size = %d \n", connectTiles.size());
    if( connectTiles.size() >= 2 )
    {
        for (int i = 0 ; i < connectTiles.size(); i ++) {
            connectTiles[i]->isEliminate = true;
        }
        origiTile->isEliminate = true;
    }
    
}

CTile* MainGameContrl::GetTileByPos(int pX, int pY)
{
    int Idx =  pX *ALL_TILE_ROW_NUM + pY;
    if (Idx >= tiles.size()) {
        return nullptr;
    }
    return &tiles[Idx];
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
            CTile tile;
            int randFruitIdx = rand() % 3;
            tile.SetRender(mainRender);
            tile.SetType((TileType)randFruitIdx);
            tile.position.first = INIT_TILE_POS_X + i*55;
            tile.position.second = INIT_TILE_POS_Y + j*55;
            tiles.push_back(tile);
        }
    }
    eventManeger::Instance()->RigisterEvent(eventManeger::Instance()->ON_MOUSE_CLICK, OnMouseClickEventCallBack);
    
}



void MainGameContrl::Render(SDL_Renderer* mainRender)
{
    texManager::Instance()->renderTexture(bgObj, mainRender, 0, 0);
    std::vector<CTile>::iterator it;
    for (it=tiles.begin(); it!=tiles.end(); ++it)
    {
        if( it->isEliminate == true )
        {
            continue;
        }
        texManager::Instance()->renderTexture( &it->texObj, mainRender, it->position.first, it->position.second);
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
        CaculateConnect();
    }
}

CTile* MainGameContrl::GetTouchTile(int mX, int mY)
{
    for (int i = 0; i < tiles.size(); i ++ ) {
            CTile tile = tiles[i];
            if( mX >= tile.position.first && mX <= tile.position.first + tile.texObj.width &&
                       mY >= tile.position.second && mY <= tile.position.second + tile.texObj.height )
            {
                return &tiles[i];
            }
    }

    return nullptr;
}

