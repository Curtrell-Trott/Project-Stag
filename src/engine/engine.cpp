#include "engine.h"

//TODO:
//Make a way to change the position of the window
//Add a way to set the name of the game and make it the name of the window
engine::engine(game mygame) : screen_width(mygame.width), screen_height(mygame.height)
{
    window = SDL_CreateWindow("It Begins", 30, 30, screen_width, screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE); // MAKE RESIZABLE
    if(!window)
        std::cout << "could not make window";

    if(SDL_Init(SDL_INIT_VIDEO) == -1)
        std::cout << "could not init window";    

    context = SDL_GL_CreateContext(window); 

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  24);

    if(gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress) == -1)
    {
        std::cout << "Glad was not initialized" << std::endl;
    }
}
engine::~engine()
{
    
}