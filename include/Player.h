//
// Created by jedra on 20.10.2019.
//

#ifndef INC_2D_GAMES_EX1_PLAYER_H
#define INC_2D_GAMES_EX1_PLAYER_H


#include <SDL2/SDL_render.h>
#include "GameObject.h"

class Player : public GameObject{
    int speedX, speedY;
    SDL_Texture *playerTexture;
public:
    void setSpeedX(int speed);
    void setSpeedY(int speed);
    Player();
    Player(int x, int y);
    ~Player();
    //bool loadTexture(std::string path);
    void update();
    void start();

};


#endif //INC_2D_GAMES_EX1_PLAYER_H
