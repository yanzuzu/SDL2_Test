//
//  CSurface.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/9.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef CSurface_hpp
#define CSurface_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class CSurface {
public:
    CSurface();
    
public:
    static SDL_Surface* OnLoad(std::string File);
    static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};

#endif /* CSurface_hpp */
