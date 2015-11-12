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
#include <utility>

class CTile
{
public:
    CTile();
public:
    CTextureObj texObj;
    std::pair<int, int> position;
};
#endif /* CTile_hpp */
