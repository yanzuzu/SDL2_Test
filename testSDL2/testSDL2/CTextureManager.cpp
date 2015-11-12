//
//  CTexture.cpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/9.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#include "CTextureManager.hpp"

CTextureManager::CTextureManager() {
}



SDL_Texture* CTextureManager::LoadImage(const std::string &file, SDL_Renderer *ren)
{
    SDL_Texture *texture = nullptr;
    //Load the image
    texture = IMG_LoadTexture( ren, file.c_str());
    return texture;

}

void CTextureManager::renderTexture(CTextureObj *texObj, SDL_Renderer *ren, int x, int y){
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    texObj->posX = x;
    texObj->posY = y;
    //Query the texture to get its width and height to use
    SDL_QueryTexture(texObj->tex, NULL, NULL, &dst.w, &dst.h);
    texObj->width = dst.w;
    texObj->height = dst.h;
    SDL_RenderCopy(ren, texObj->tex, NULL, &dst);
}
