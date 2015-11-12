//
//  CText.cpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/10.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#include "CText.hpp"

CText::CText(){}

SDL_Texture* CText::renderText(const std::string &message, const std::string &fontFile,
                               SDL_Color color, int fontSize, SDL_Renderer *renderer){
    
    //Open the font
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr){
        printf("TTF_OpenFont is null\n");
        return nullptr;
    }
    //We need to first render to a surface as that's what TTF_RenderText
    //returns, then load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr){
        TTF_CloseFont(font);
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr){
        printf("texture is null\n");
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
    
}
