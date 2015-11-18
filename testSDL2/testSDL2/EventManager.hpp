//
//  EventManager.hpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/10.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef EventManager_hpp
#define EventManager_hpp

#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <vector>
#include <map>
#include <string>

class EventMouseClickData
{
public:
    int mX;
    int mY;
};

class EventManager
{
private:
    
public:
    EventManager() {};
    ~EventManager() {};
    
    const std::string ON_MOUSE_CLICK = "ON_MOUSE_CLICK";
    
    std::map<std::string, std::vector<std::function<void(void*)>>> dataMaps;
    void RigisterEvent(std::string,std::function<void(void*)>);
    void FireEvent(std::string, void*);
    
};
#endif /* EventManager_hpp */
