#include <iostream>
#pragma once

class Collider
{
    private:
    public:
        bool isActive;
        float x, y, w, h;
        Collider();
        Collider(float PosX, float PosY, float Width, float Height);
        void MakeCol(float PosX, float PosY, float Width, float Height);
        ~Collider();
};