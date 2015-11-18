//
//  EventManager.cpp
//  testSDL2
//
//  Created by Sam Lo on 2015/11/10.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#include "EventManager.hpp"


void EventManager::RigisterEvent(std::string eventId,std::function<void(void*)> callBack)
{
    dataMaps[eventId].push_back(callBack);
}

void EventManager::FireEvent(std::string eventId , void *args)
{
    if( dataMaps.count(eventId) == 0 )
    {
        return;
    }
    for( int i = 0; i < dataMaps[eventId].size(); i ++ )
    {
        std::function<void(void*)> f = dataMaps[eventId][i];
        f(args);
    }
}