#include <iostream>
#include "engine/resource_manager.h"
#include "engine/game_object.h"
#include "engine/collider.h"
#pragma once

class Enemy : public GameObject
{
    private:
        //Collider col;
    public:
        Enemy();
        void Init();
        void Update(double deltaTime);
        ~Enemy();
};