#include <iostream>
#include <list>
#include "SDL2/SDL.h"
#include "glad/glad.h"

#include "game.h"
#include "engine/resource_manager.h"

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

game stag(SCREEN_WIDTH, SCREEN_HEIGHT);

std::list<GameObject*> GameObject::ObjList;

int main(int argv, char** args) 
{
    SDL_Window *window;
    SDL_GLContext context;

    window = SDL_CreateWindow("It Begins", 30, 30, stag.width, stag.height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE); // MAKE RESIZABLE
    if(!window)
        std::cout << "could not make window";

    if(SDL_Init(SDL_INIT_VIDEO) == -1)
        std::cout << "could not init window";    

    context = SDL_GL_CreateContext(window); 
    if(!context)
        std::cout << "could not make context";

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  24);

    if(gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress) == -1)
    {
        std::cout << "Glad was not initialized" << std::endl;
    }

    // OpenGL configuration
    // --------------------
    glViewport(0, 0, stag.width, stag.height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // initialize game
    // ---------------
    stag.Init();

    // deltaTime variables
    // -------------------
    Uint64 currentFrame = SDL_GetPerformanceCounter();
    Uint64 lastFrame = 0.0f;
    double deltaTime = 0.0f;

    while (stag.State == GAME_ACTIVE)
    {
        
        lastFrame = currentFrame;
        currentFrame = SDL_GetPerformanceCounter();

        deltaTime =  ((currentFrame - lastFrame)*1000 / (double)SDL_GetPerformanceFrequency());

        stag.Update(deltaTime);
        stag.ProcessInput(deltaTime);
        
        //Maybe add a fixed update?

        //render
        glClearColor(0.49f, 0.30f, 0.57f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        stag.Render();

        SDL_GL_SwapWindow(window);
    }

    // delete all resources as loaded using the resource manager
    // ---------------------------------------------------------
    ResourceManager::Clear();
    
    //SDL terminate thingie
    return 0;
}
