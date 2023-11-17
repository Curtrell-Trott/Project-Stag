#include "game.h"

SpriteRenderer  *Renderer;
//GameObject      *Player;

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
    //glm::vec2 playerPos = glm::vec2(this->width / 2.0f, this->height / 2.0f);
    //Player = new GameObject(playerPos, PLAYER_SIZE, ResourceManager::GetTexture("princess"));
    Player player;

    std::cout << GameObject::ObjList.empty();
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

void game::Render()
{
    if(this->State == GAME_ACTIVE){
        //Player->Draw(*Renderer);
    }
}
