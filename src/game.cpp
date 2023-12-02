#include "game.h"

#include "engine/imgui/imgui.h"
#include <cmath> 

//NOTE: COULD BE USEFUL FOR WINDOW REZ THINGS
//https://stackoverflow.com/questions/47979639/how-is-it-possible-to-determine-the-correct-drawable-size-of-a-window-on-windows
SpriteRenderer  *Renderer;
Player *player;
GameObject  *enemy;
GameObject  *box;

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
    ResourceManager::LoadTexture("res\\sprites\\princess_idle.png", true, "princess_idle");
    ResourceManager::LoadTexture("res\\sprites\\princess_forward.png", true, "princess_forward");
    ResourceManager::LoadTexture("res\\sprites\\princess_back.png", true, "princess_back");
    ResourceManager::LoadTexture("res\\sprites\\princess_swing1.png", true, "princess_swing1");
    ResourceManager::LoadTexture("res\\sprites\\princess_swing2.png", true, "princess_swing2");
    ResourceManager::LoadTexture("res\\sprites\\enemy.png", true, "enemy");
    ResourceManager::LoadTexture("res\\sprites\\Sprite-0001.png", true, "box");

    //start input handler
    //InputMap::Handler();
    
    //game object init
    player = new Player();
    enemy = new GameObject(glm::vec2(1200, 300), glm::vec2((ResourceManager::GetTexture("enemy").Width/18), (ResourceManager::GetTexture("enemy").Height/18)), ResourceManager::GetTexture("enemy"));


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
    ImGui::Begin("Hello");
    //ImDrawList::AddRect(ImVec2(0,0), ImVec2(400,400), 1, 0, 0, 0);
    ImGui::GetForegroundDrawList()->AddRect(ImVec2(player -> Position.x, player -> Position.y), ImVec2(player -> Position.x + player -> Size.x, player -> Position.y + player -> Size.y), IM_COL32(0, 255, 0, 200), 0, 0, 10);
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
}

bool game::CheckCollisions(GameObject &one, GameObject &two) // AABB - AABB collision
{
    // collision x-axis?
    bool collisionX = one.Position.x + std::abs(one.Size.x) >= two.Position.x &&
        two.Position.x + two.Size.x >= one.Position.x;
    // collision y-axis?
    bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
        two.Position.y + two.Size.y >= one.Position.y;
    // collision only if on both axes
    return collisionX && collisionY;
}


