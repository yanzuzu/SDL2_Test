//
//  CText.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/10.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef CText_hpp
#define CText_hpp

#include <string>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class CText
{
public:
    CText();
    SDL_Texture* renderText(const std::string &message, const std::string &fontFile,
                            SDL_Color color, int fontSize, SDL_Renderer *renderer);
};
#endif /* CText_hpp */
