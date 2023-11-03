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
        game currgame;

        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        
        unsigned int screen_width  = 800;
        unsigned int screen_height = 480;
        
    public:
        engine();
        //void initGame(game game);
        void loop();
        ~engine();
};