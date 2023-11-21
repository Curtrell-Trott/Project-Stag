#include "player.h"

Player::Player()
{
    Position = glm::vec2(800 / 2.0f, 600 / 2.0f); //set position to the center of the screen
    Size = glm::vec2(-200, 200);
    Sprite = ResourceManager::GetTexture("princess");
    ObjList.push_front(this);
}

void GameObject::Init()
{
    //std::cout << "init Tick" << std::endl;
}
void GameObject::Update(double deltaTime)
{
    
}
void GameObject::ProcessInput(double deltaTime, SDL_Event e)
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_UP])
        Position.y += -0.5f * deltaTime;
    if(keystate[SDL_SCANCODE_DOWN])
        Position.y += 0.5f * deltaTime;
    if(keystate[SDL_SCANCODE_RIGHT])
        Position.x += 0.5f * deltaTime;
    if(keystate[SDL_SCANCODE_LEFT])
        Position.x += -0.5f * deltaTime;
    
}

Player::~Player()
{
    
}
