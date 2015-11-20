//
//  CTile.cpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/11.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#include "CTile.hpp"

CTile::CTile()
{
    isEliminate = false;
}

void CTile::SetRender(SDL_Renderer* pRender)
{
    mainRender = pRender;
}

TileType CTile::GetType()
{
    return type;
}

void CTile::SetType(TileType pType)
{
    type = pType;
    std::string imageName = "";
    switch (pType) {
        case Yellow:
            imageName = "fruit_1.png";
            break;
        case Red:
            imageName = "fruit_2.png";
            break;
        case Green:
            imageName = "fruit_3.png";
            break;
        default:
            break;
    }
    
    SDL_Texture *itemImg = Singleton<CTextureManager>::Instance()->LoadImage(imageName, mainRender);
    texObj.tex = itemImg;
}