#include "game.h"

#include "engine/imgui/imgui.h"
#include <cmath> 

//NOTE: COULD BE USEFUL FOR WINDOW REZ THINGS
//https://stackoverflow.com/questions/47979639/how-is-it-possible-to-determine-the-correct-drawable-size-of-a-window-on-windows
SpriteRenderer  *Renderer;
Player *player;
GameObject  *enemy;

game::game()
{

}
game::game(unsigned int width, unsigned int height) : State(GAME_ACTIVE), width(width), height(height)
{
    
}
game::~game()
{
    delete Renderer;
}
  
void game::Init()
{
    // load shaders
    //ResourceManager::LoadShader("shaders/sprite.vert", "shaders/sprite.frag", nullptr, "sprite");
    ResourceManager::LoadShader("res\\shaders\\sprite.vert", "res\\shaders\\sprite.frag", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width), static_cast<float>(this->height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    // load textures
    ResourceManager::LoadTexture("res\\sprites\\image.png", true, "princess");
    ResourceManager::LoadTexture("res\\sprites\\enemy.png", true, "enemy");

    //start input handler
    //InputMap::Handler();
    
    //game object init
    player = new Player();
    enemy = new GameObject(glm::vec2(500, 600 / 2.0f), glm::vec2((ResourceManager::GetTexture("enemy").Width/23), (ResourceManager::GetTexture("enemy").Height/23)), ResourceManager::GetTexture("enemy"));


    //const Uint8* test = InputMap::keystate[SDL_SCANCODE_UP];
    //InputMap::AddAction("UP", &InputMap::keystate[SDL_SCANCODE_UP]);

    //Run Init on all objects
    if(this->State == GAME_ACTIVE)
    {
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> Init();
        }
    }
}

void game::Update(double deltaTime)
{
    ImGui::Begin("Hello, world!");
    ImGui::Text("Player PosX: %f", player->Position.x);
    ImGui::Text("Player PosX: %f", enemy->Position.x); 
    ImGui::End();
    //Run Update on all objects
    if(this->State == GAME_ACTIVE)
    {
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> Update(deltaTime);
            //send the current obj and a list of the objs without the current obj
            DoCollision(obj, GameObject::ObjList);
            //obj -> Collision(obj, ObjList.pop(obj)); // if i decide to do collision checks on the player side 
        }
    }
}

void game::ProcessInput(double deltaTime)
{
    InputMap::Handler();
    player -> ProcessInput(deltaTime);
}

void game::Render()
{
    if(this->State == GAME_ACTIVE){
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> Draw(*Renderer);
        }
    }
}
void game::DoCollision(GameObject *obj, std::list<GameObject*> checkList)
{
    for(GameObject* c_obj : GameObject::ObjList)
        if(obj != c_obj){
            if(CheckCollisions(*obj, *c_obj))
                obj -> OnCollision(c_obj);
        }
    //iterate thru each obj in the list and check collision with the obj given
    /*for(GameObject* compareObj : checkList)
    {
        if(CheckCollision(obj, compareObj))
            obj -> OnCollision(compareObj);
    }*/
}

bool game::CheckCollisions(GameObject &one, GameObject &two) // AABB - AABB collision
{
    // collision x-axis?
    bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
        two.Position.x + two.Size.x >= one.Position.x;
    // collision y-axis?
    bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
        two.Position.y + two.Size.y >= one.Position.y;
    // collision only if on both axes
    return collisionX && collisionY;
}

