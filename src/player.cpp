#include "player.h"

Player::Player()
{
    Position = glm::vec2(800 / 2.0f, 600 / 2.0f); //set position to the center of the screen
    Sprite = ResourceManager::GetTexture("princess");
    //Size = glm::vec2(-200, 200);
    Size = glm::vec2((Sprite.Width/20)*-1.0f, (Sprite.Height/20));
    HurtBox.MakeCol(Position.x*1, Position.y*1, Size.x*1, Size.y*1); // NOTE: maybe decrease the hurtbox size
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

void GameObject::OnCollision(GameObject obj)
{
    //Do something with the object that has been collided with
}

Player::~Player()
{
    
}
