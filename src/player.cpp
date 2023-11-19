#include "player.h"

Player::Player()
{
    Position = glm::vec2(800 / 2.0f, 600 / 2.0f); //set position to the center of the screen
    Size = glm::vec2(100, 100);
    Sprite = ResourceManager::GetTexture("princess");
    ObjList.push_front(this);
}

void GameObject::Init()
{
    std::cout << "init Tick" << std::endl;
}
void GameObject::Update(float deltaTime)
{
    std::cout << "Update Tick" << std::endl;
}
void GameObject::ProcessInput(float deltaTime)
{
    std::cout << "Input Tick" << std::endl;
}

Player::~Player()
{
    
}
