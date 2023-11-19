#include "game.h"

SpriteRenderer  *Renderer;

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
    
    //game object init
    Player *player = new Player();

    //Run Init on all objects
    if(this->State == GAME_ACTIVE)
    {
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> Init();
        }
    }
}

void game::Update(float deltaTime)
{
    //Run Update on all objects
    if(this->State == GAME_ACTIVE)
    {
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> Update(deltaTime);
        }
    }
}

void game::ProcessInput(float deltaTime)
{
    SDL_Event e;
    if(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            std::cout << "Quitting Game";
            this->State = GAME_QUIT;
        }   
    }

    //Run Init on all objects
    if(this->State == GAME_ACTIVE){
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> ProcessInput(deltaTime);
        }
    }     
}

void game::Render()
{
    if(this->State == GAME_ACTIVE){
        for(GameObject* obj : GameObject::ObjList)
        {
            obj -> Draw(*Renderer);
        }
        //GameObject::ObjList.front() -> Draw(*Renderer);
    }
}
