#include "collider.h"

Collider::Collider()
{
    
}
Collider::Collider(float PosX, float PosY, float Width, float Height)
{
    x = PosX;
    y = PosY;
    w = Width;
    h = Height;
}
void Collider::MakeCol(float PosX, float PosY, float Width, float Height)
{
    x = PosX;
    y = PosY;
    w = Width;
    h = Height;
}
Collider::~Collider()
{

}