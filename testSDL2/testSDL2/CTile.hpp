//
//  CTile.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/11.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef CTile_hpp
#define CTile_hpp

#include <stdio.h>
#include "CTextureObj.hpp"
#include "Singleton.h"
#include "CTextureManager.hpp"
#include <utility>
#include <string>

enum TileType
{
    Yellow = 0,
    Red,
    Green,
};
class CTile
{
private:
    TileType type;
    SDL_Renderer *mainRender;
public:
    CTile();
public:
    void SetType(TileType pType);
    TileType GetType();
    
    void SetRender(SDL_Renderer*);
    
    bool isEliminate;
    CTextureObj texObj;
    std::pair<int, int> position;
};
#endif /* CTile_hpp */
