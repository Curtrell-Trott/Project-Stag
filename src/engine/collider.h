#include "game_object.h"
#include <vector>
#pragma once

class BoxCollider
{
    private:
        //GameObject *parent;

    public:
        float Wx,Wy,w,h, Ox,Oy; //make the type match the game object position
        static std::vector<BoxCollider*> colliders;
        static int index; //make the int unsigned perhaps
        //GameObject parentOBJ;
        
        //BoxCollider(GameObject &parent);
        BoxCollider(GameObject *parent, float Wx = 0, float Wy = 0, float w = 1, float h = 1);
        
        void setPos(float x, float y);
        void setSize(float w, float h);
        void Update();
        void Collisions();
        bool CheckCollisions(BoxCollider& col1, BoxCollider& col2);

        ~BoxCollider();
};