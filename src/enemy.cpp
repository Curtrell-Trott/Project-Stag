#include "enemy.h"

Enemy::Enemy()
{
    Position = glm::vec2(1200, 300);
    Size = glm::vec2((ResourceManager::GetTexture("enemy").Width/18), (ResourceManager::GetTexture("enemy").Height/18));
    Sprite = ResourceManager::GetTexture("enemy");
    col.x = this -> Position.x;
    col.y = this -> Position.y;
    col.w = this -> Size.x;
    col.h = this -> Size.y;
    col.mode = 1;
    Drawable = true;
}

void Enemy::Init()
{
    
}
void Enemy::Update(double deltaTime)
{
    
}