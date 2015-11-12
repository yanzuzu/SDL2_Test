//
//  CTextureObj.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/11.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef CTextureObj_hpp
#define CTextureObj_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class CTextureObj
{
public:
    CTextureObj();
    SDL_Texture *tex;
    int width = 0;
    int height = 0;
    int posX = 0;
    int posY = 0;
};
#endif /* CTextureObj_hpp */
