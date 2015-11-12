//
//  CSurface.cpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/9.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#include "CSurface.hpp"
#include <iostream>
#include <string>

CSurface::CSurface() {
}


SDL_Surface* CSurface::OnLoad(std::string filename) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
    
    if((Surf_Temp = IMG_Load(filename.c_str())) == NULL) {
        std::cout << "load img failed error : " << SDL_GetError() << std::endl;
        return NULL;
    }
    
    Surf_Return = SDL_ConvertSurfaceFormat(Surf_Temp, SDL_PIXELFORMAT_RGBA8888, 0);
    //Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
    
    return Surf_Return;
}



bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
    
    SDL_Rect DestR;
    
    DestR.x = X;
    DestR.y = Y;
    
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
    
    return true;
}