#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "SDL2/SDL.h"
#include "glm/glm.hpp"

#include "engine/resource_manager.h"
#include "engine/sprite_renderer.h"
#include "engine/game_object.h"
#include "engine/input_handler.h"

#include "player.h"
#include "enemy.h"
#pragma once

//TODO: make a input processor
enum GameState{
    GAME_ACTIVE,
    GAME_QUIT,
    GAME_MENU
};


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
        void DoCollision(GameObject* obj, std::list<GameObject*> checkList);
        bool CheckCollisions(GameObject &one, GameObject &two);
        
};