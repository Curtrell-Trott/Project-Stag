#include "collider.h"

/*BoxCollider::BoxCollider(GameObject &parent)
{
    Ox = 0;
    Oy = 0;
    w = 1;
    h = 1;

    Wx = parent.Position.x + Ox;
    Wy = parent.Position.y + Oy;

    colliders.push_back(*this);

}*/

BoxCollider::BoxCollider(GameObject *parent, float x, float y, float w, float h)
{
    //this -> parent = parent;
    this -> Ox = x;
    this -> Oy = y;
    this -> w = w;
    this -> h = h;

    //Wx = parent->Position.x + Ox;
    //Wy = parent->Position.y + Oy;
    
    colliders.push_back(this);
    //index = 0;
}
        
void BoxCollider::setPos(float x, float y)
{
    Ox = x;
    Oy = y;
}

void BoxCollider::setSize(float w, float h)
{
    this -> w = w;
    this -> h = h;
}

void BoxCollider::Update()
{
    //update the positions
    //x = parent pos.x + ox
    //y = parent pos.y + oy
    //std::cout << (parent->Drawable);
    //Wx = parent -> Position.x + Ox;
    //Wy = parent -> Position.y + Oy;
}

void BoxCollider::Collisions()
{
    //iterate thru each collsion box and check for collision w/ all the rest
    //if there is one call the 'collision made' method in each of the parents
    /*if(colliders[index]->parent != this -> parent) //if the parents of both colliders arent the same
        if(CheckCollisions(*colliders[index], *this))
        {
            //call both objects OnCollision
            this -> parent -> OnCollision(colliders[index]->parent); //make it so that OnCollision takes the collider instead of the parent object
            colliders[index]->parent -> OnCollision(this -> parent);
        }*/
    /*index = (index + 1) % 10; //index not counting past 1
    if(index == 1)
        std::cout << index << " ";*/
}

bool BoxCollider::CheckCollisions(BoxCollider& col1, BoxCollider& col2) // AABB - AABB collision
{

    // collision x-axis?
    bool collisionX = col1.Wx + col1.w >= col2.Wx &&
        col2.Wx + col2.w >= col1.Wx;
    // collision y-axis?
    bool collisionY = col1.Wy + col1.h >= col2.Wy &&
        col2.Wy + col2.h >= col1.Wy;
    
    // collision only if on both axes
    return collisionX && collisionY;
}

BoxCollider::~BoxCollider()
{}
//~Collider();