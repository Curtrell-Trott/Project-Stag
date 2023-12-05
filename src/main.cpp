#include "engine/imgui/imgui.h"
#include "engine/imgui/imgui_impl_sdl2.h"
#include "engine/imgui/imgui_impl_opengl3.h"

#include <iostream>
#include <list>
#include "SDL2/SDL.h"
#include "glad/glad.h"

#include "game.h"
#include "engine/resource_manager.h"

const unsigned int SCREEN_WIDTH = 1600;
const unsigned int SCREEN_HEIGHT = 900;

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

    // ImGui Setup
    // --------------------
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui_ImplOpenGL3_Init();
    ImGui_ImplSDL2_InitForOpenGL(window, context);


    // initialize game
    // ---------------
    stag.Init();

    // Tick and Frame counters
    // -------------------
	Uint32 totalFrameTicks = 0;
	Uint32 totalFrames = 0;

    while (stag.State == GAME_ACTIVE)
    {
        totalFrames++;
		Uint32 startTicks = SDL_GetTicks();
		Uint64 startPerf = SDL_GetPerformanceCounter();

        //Draw ImGUI things
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        //NOTE: MAYBE DONT DO THIS EVERY UPDATE
        int width, height;
        SDL_GetWindowSize(window, &width, &height);
        
        //GAME LOOPS RUN HERE
        //--------------
        //event updating
        stag.Update();
        stag.ProcessInput();
        SDL_Event e;
        if(SDL_PollEvent(&e))
        {
            ImGui_ImplSDL2_ProcessEvent(&e);
            if(e.type == SDL_QUIT)
            {
                std::cout << "Quitting Game";
                stag.State = GAME_QUIT;
            }   
        }
        //deltaTime calculation
        Uint32 time = SDL_GetTicks();
		stag.deltaTime = (time - stag.lastUpdate) / 1000.0f;
        stag.lastUpdate = time;
        //render
        glViewport(0, 0, width, height);
        glClearColor(0.49f, 0.30f, 0.57f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        stag.Render();
        
        // End frame timing
		Uint32 endTicks = SDL_GetTicks();
		Uint64 endPerf = SDL_GetPerformanceCounter();
		Uint64 framePerf = endPerf - startPerf;
		float frameTime = (endTicks - startTicks) / 1000.0f;
		totalFrameTicks += endTicks - startTicks;
        // Strings to display
        if(ImGui::Begin("Perfomance tracker")){
		ImGui::Text("Current FPS:  %f", (1.0f / frameTime));
		ImGui::Text("Average FPS:  %f", (1000.0f / ((float)totalFrameTicks / totalFrames)));
		ImGui::Text("Current Perf: %lld", (framePerf));
        }
        ImGui::End();
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        

        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    // delete all resources as loaded using the resource manager
    // ---------------------------------------------------------
    ResourceManager::Clear();
    
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    //SDL terminate thingie
    return 0;
}
