#include <iostream>
#include "engine/resource_manager.h"
#include "engine/game_object.h"
#pragma once

class Player : public GameObject
{
    private:
        float speed;
        float attackTime = 0;
        Collider hit;
    public:
        Player();
        Player(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec4 color = glm::vec4(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
        //Collider col;
        void Init();
        void ProcessInput(double deltaTime);
        void Update(double deltaTime);
        //void Update(double deltaTime) override;
        ~Player();
};