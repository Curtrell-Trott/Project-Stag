#include <iostream>
#include <vector>
#include "SDL2/SDL.h"
#include "glm/glm.hpp"

#include "engine/resource_manager.h"
#include "engine/sprite_renderer.h"
#include "engine/game_object.h"
#include "player.h"
#pragma once

//TODO: make a input processor
enum GameState{
    GAME_ACTIVE,
    GAME_QUIT,
    GAME_MENU
};

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 100.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(500.0f);

class game
{
    private:
        
    public:
        GameState State;
        unsigned int width, height;
        
        game(unsigned int width, unsigned int height);
        game();
        ~game();

        void Init();
        void Update(double deltaTime);
        void AddObject(GameObject gameObject);
        void ProcessInput(double deltaTime);
        void Render();
        
};