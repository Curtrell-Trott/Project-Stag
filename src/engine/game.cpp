#include "game.h"

SpriteRenderer  *Renderer;
GameObject      *Player;

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
    
    //game object config
    GameObject.test = 4;
    std::cout << GameObject.test;
    //glm::vec2 playerPos = glm::vec2(this->width / 2.0f, this->height / 2.0f);
    //Player = new GameObject(playerPos, PLAYER_SIZE, ResourceManager::GetTexture("princess"));
}

void game::Update(float deltaTime)
{

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
}

void game::AddObject(GameObject gameObject)
{
    //ObjList.push_back(gameObject);
}

void game::Render()
{
    if(this->State == GAME_ACTIVE){
        Player->Draw(*Renderer);
    }
}
