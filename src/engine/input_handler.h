#include <iostream>
#include <map>
#include <algorithm>
#include <list>
#include <string>

#include "SDL2/SDL.h"
#pragma once

struct Input
{
    std::string name;
    std::list<const Uint8*> keys;
};

class InputMap
{
    //TODO: Prob just store the input stuff in a map
    private:
        InputMap() {}
        //static std::list<Input> mapping;
        //list as the value 
        static std::map<std::string, std::list<const Uint8*>> mapping;

    public:   
        //Process Input
        static const Uint8* keystate;
        static void Handler();
        static void AddAction(std::string name, const Uint8* key = NULL);
        static void AddKey(std::string name, const Uint8* key);
        static bool IsPressed(std::string name);
};