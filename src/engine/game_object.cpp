#include "game_object.h"


GameObject::GameObject() : Position(0.0f, 0.0f), Size(1.0f, 1.0f), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false), Destroyed(false) 
{
    ObjList.push_front(this);
    //this -> col.setCollider(Position.x, Position.y, Size.x, Size.y);
}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec4 color, glm::vec2 velocity) : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false), Destroyed(false) 
{
    ObjList.push_front(this);
    //this -> col.setCollider(Position.x, Position.y, Size.x, Size.y);
}

void GameObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}
void GameObject::Init()
{
    
}

void GameObject::Update(double deltaTime)
{

}

void GameObject::OnCollision(GameObject* obj)
{
    
}

float GameObject::Timer(float time)
{
    time -= 0.1f;
    return time;
}