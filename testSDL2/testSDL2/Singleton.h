//
//  Singleton.h
//  testSDL2
//
//  Created by Sam Lo on 2015/11/10.
//  Copyright © 2015年 Sam Lo. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h


template <class T>
class Singleton
{
public:
    static T* Instance() {
        if(!m_pInstance) m_pInstance = new T;
        //assert(m_pInstance != NULL);
        return m_pInstance;
    }
protected:
    Singleton();
    ~Singleton();
private:
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);
    static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance=NULL;

#endif /* Singleton_h */
