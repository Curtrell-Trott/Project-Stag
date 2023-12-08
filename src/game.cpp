#include "game.h"

#include "engine/imgui/imgui.h"
#include <cmath> 

//NOTE: COULD BE USEFUL FOR WINDOW REZ THINGS
//https://stackoverflow.com/questions/47979639/how-is-it-possible-to-determine-the-correct-drawable-size-of-a-window-on-windows
//Note: It FEELS like there is some input lag... Ever since I changed the game looping stuff and the deltaTime calculation https://thenumb.at/cpp-course/sdl2/08/08.html
//https://gamedev.stackexchange.com/questions/110825/how-to-calculate-delta-time-with-sdl 
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
    ResourceManager::LoadTexture("res\\sprites\\background.png", true, "bg");

    //start input handler
    //InputMap::Handler();
    
    //game object init
    player = new Player(glm::vec2(400, 300), glm::vec2(ResourceManager::GetTexture("princess_idle").Width/15, ResourceManager::GetTexture("princess_idle").Height/15), ResourceManager::GetTexture("princess_idle"));
    enemy = new Enemy();


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

void game::Update()
{
    //Run Update on all objects
    if(this->State == GAME_ACTIVE)
    {
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> Update(deltaTime);

            for(Collider col : obj -> cols){
                //send the current obj and a list of the objs without the current obj
                if(col.mode == 2 && col.isActive == true)
                    ImGui::GetForegroundDrawList()->AddRect(ImVec2(col.x, col.y), ImVec2(col.x + col.w, col.y + col.h), IM_COL32(255, 0, 0, 200), 0, 0, 10);
                else if(col.mode == 1 && col.isActive == true)
                    ImGui::GetForegroundDrawList()->AddRect(ImVec2(col.x, col.y), ImVec2(col.x + col.w, col.y + col.h), IM_COL32(0, 255, 0, 200), 0, 0, 10);
            }
    
            DoCollision(obj, GameObject::ObjList);
            //obj -> Collision(obj, ObjList.pop(obj)); // if i decide to do collision checks on the object side 
        }
    }
}

void game::ProcessInput()
{
    InputMap::Handler();
    player -> ProcessInput(this -> deltaTime);
}

void game::Render()
{
    if(this->State == GAME_ACTIVE){ // can probably remove this if statment and all the similar ones in this file
        Renderer->DrawSprite(ResourceManager::GetTexture("bg"), glm::vec2(0.0f, 0.0f), glm::vec2(this->width*3, this->height*3), 0.0f); //renders the bg
        for(GameObject* obj : GameObject::ObjList)
        {
            if(obj -> Drawable == true){
                Renderer->DrawSprite(obj -> Sprite, glm::vec2(obj -> Position.x-9, obj -> Position.y+7), glm::vec2(obj->Size.x, obj->Size.y), 0.0f, glm::vec4(0,0,0,0.3f)); //creates dropshadow
                obj -> Draw(*Renderer);
            }
        }
    }
}
void game::DoCollision(GameObject *obj, std::list<GameObject*> checkList)
{
    //Loop thru the colliders of the objects 
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


