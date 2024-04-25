#include "player.h"

Player::Player(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec4 color, glm::vec2 velocity) : GameObject(pos, size, sprite, color, velocity)
{
    speed = 600;
    Sprite = ResourceManager::GetTexture("princess_idle");
    BoxCollider test(this);

    /*col.setCollider(50, 120, 50, 50);

    hit.setCollider(80, 40, 230, 200);
    hit.mode = 2;
    hit.isActive = false;

    cols.push_back(col);
    cols.push_back(hit);*/
}

void Player::Init()
{
    
}
void Player::Update(double deltaTime)
{
    Position = glm::vec2(Position.x + (Velocity.x*deltaTime), Position.y + (Velocity.y*deltaTime)); 
}
void Player::ProcessInput(double deltaTime)
{
    Velocity = glm::vec2(0,0);
    Sprite = ResourceManager::GetTexture("princess_idle");
    //cols[1].isActive = false;
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_E])
        Velocity.y = -1 * speed;
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
        //cols[1].isActive = true;
        Sprite = ResourceManager::GetTexture("princess_swing2");
    }
    Size = glm::vec2((Sprite.Width/15), (Sprite.Height/15));
}

void Player::OnCollision(GameObject* obj)
{
    std::cout << "made collision" << std::endl;
    //Do something with the object that has been collided with
}

Player::~Player()
{
    
}
