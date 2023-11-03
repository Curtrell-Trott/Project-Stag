#include <iostream>
#pragma once

enum GameState{
    GAME_ACTIVE,
    GAME_QUIT,
    GAME_MENU
};

class game
{
    private:
    
    public:
        GameState State;
        unsigned int width, height;
        
        game(unsigned int width, unsigned int height);
        ~game();

        void Init();
        void Update();
        void Render();
};