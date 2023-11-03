#include <iostream>

#include "SDL2/SDL.h"
#include "glad/glad.h"
#include "game.h"
#pragma once

//This will be a static(?) class that will take in a game object. It will then create a window using SDL and draw using opengl. Make a input handler
class engine
{
    private:
        SDL_Window *window;
        SDL_GLContext context;
        
        unsigned int screen_width  = 800;
        unsigned int screen_height = 480;
        
    public:
        engine(game game);
        ~engine();
};