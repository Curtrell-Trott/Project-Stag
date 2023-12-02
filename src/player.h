#include <iostream>
#include "engine/resource_manager.h"
#include "engine/game_object.h"
#include "engine/collider.h"
#pragma once

class Player : public GameObject
{
    private:
        float speed;
        float attackTime;
    public:
        Player();
        void ProcessInput(double deltaTime);
        //void Update(double deltaTime) override;
        ~Player();
};