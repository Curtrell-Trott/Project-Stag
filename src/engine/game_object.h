#include "glad/glad.h"
#include "glm/glm.hpp"
#include <list>
#include <iostream>
#include "SDL2/SDL.h"
 
#include "texture.h"
#include "sprite_renderer.h"
#pragma once

// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.
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
        bool        Destroyed;
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