#include "glad/glad.h"
#include "glm/glm.hpp"
#include "engine/imgui/imgui.h"
#include <list>
#include <vector>
#include <iostream>
#include "SDL2/SDL.h"
 
#include "texture.h"
#include "sprite_renderer.h"
#pragma once

// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.

struct Collider
{
    int x,y,w,h;
    int Ox, Oy;
    bool isActive = true;
    int mode = 1;

    void setCollider(int x, int y, int w, int h)
    {
        this -> x = x;
        this -> y = y;
        this -> w = w;
        this -> h = h;

        Ox = x;
        Oy = y;
    }
    void setPos(int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }
    void setSize(int w, int h)
    {
        this -> w = w;
        this -> h = h;
    }
    //Update Position with the parent's position
};

class GameObject
{
    private:
    
    public:
        static float Timer(float time);
        static std::list<GameObject*> ObjList;
        // object state
        glm::vec2   Position, Size, Velocity;
        glm::vec4   Color;
        float       Rotation;
        bool        IsSolid;
        bool        Drawable = true;
        bool        Destroyed;
        Collider    col;
        std::vector<Collider> cols;
        // render state
        Texture2D   Sprite;	
        // constructor(s)
        GameObject();
        GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec4 color = glm::vec4(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
        
        // draw sprite
        virtual void Draw(SpriteRenderer &renderer);
        virtual void Init();
        virtual void Update(double deltaTime);
        //virtual void ProcessInput(double deltaTime, SDL_Event e);
        virtual void OnCollision(GameObject* obj);
        
};