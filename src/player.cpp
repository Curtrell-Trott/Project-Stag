#include "player.h"

Player::Player()
{
    Position = glm::vec2(800 / 2.0f, 600 / 2.0f); //set position to the center of the screen
    Sprite = ResourceManager::GetTexture("princess_idle");
    //Size = glm::vec2(-200, 200);
    Size = glm::vec2((Sprite.Width/15), (Sprite.Height/15));
    speed = 0.4f;
    ObjList.push_front(this);
}

void GameObject::Init()
{
    //std::cout << "init Tick" << std::endl;
}
void GameObject::Update(double deltaTime)
{
    Position = glm::vec2(Position.x + (Velocity.x*deltaTime), Position.y + (Velocity.y*deltaTime)); 
    Size = glm::vec2((Sprite.Width/15), (Sprite.Height/15));
}
void Player::ProcessInput(double deltaTime)
{
    Velocity = glm::vec2(0,0);
    Sprite = ResourceManager::GetTexture("princess_idle");
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_E])
        Velocity.y = -1 * speed;
        //Position.y += -0.5f * deltaTime;
    if(keystate[SDL_SCANCODE_D])
        Velocity.y = 1 * speed;
    if(keystate[SDL_SCANCODE_F])
    {
        Velocity.x = 1 * speed;
        Sprite = ResourceManager::GetTexture("princess_forward");
    }
    if(keystate[SDL_SCANCODE_S])
    {
        Velocity.x = -1 * speed;
        Sprite = ResourceManager::GetTexture("princess_back");
    }
    if(keystate[SDL_SCANCODE_P])
    {
        Sprite = ResourceManager::GetTexture("princess_swing1");
        attackTime = 1;
    }
    else if(!keystate[SDL_SCANCODE_P] && attackTime > 0){
        attackTime = GameObject::Timer(attackTime);
        Sprite = ResourceManager::GetTexture("princess_swing2");
    }
}

void GameObject::OnCollision(GameObject* obj)
{
    //std::cout << "made collision" << std::endl;
    //Do something with the object that has been collided with
}

Player::~Player()
{
    
}
