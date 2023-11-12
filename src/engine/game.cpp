#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"

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
    ResourceManager::LoadShader("D:\\programming\\C++\\Project Stag\\res\\shaders\\sprite.vert", "D:\\programming\\C++\\Project Stag\\res\\shaders\\sprite.frag", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width), static_cast<float>(this->height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    // load textures
    ResourceManager::LoadTexture("D:\\programming\\C++\\Project Stag\\res\\sprites\\image.png", true, "test");
}

void game::Update(float deltaTime)
{

}
void game::Render()
{
    Renderer->DrawSprite(ResourceManager::GetTexture("test"), glm::vec2(100.0f, 100.0f), glm::vec2(100.0f, 100.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}