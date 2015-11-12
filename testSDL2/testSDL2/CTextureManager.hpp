//
//  CTexture.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/9.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef CTexture_hpp
#define CTexture_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2_image/SDL_image.h>
#include "CTextureObj.hpp"

class CTextureManager
{
public:
    CTextureManager();
    SDL_Texture* LoadImage(const std::string &file, SDL_Renderer *ren);
    void renderTexture(CTextureObj *tex, SDL_Renderer *ren, int x, int y);
};
#endif /* CTexture_hpp */
