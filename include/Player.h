//
// Created by jedra on 20.10.2019.
//

#ifndef INC_2D_GAMES_EX1_PLAYER_H
#define INC_2D_GAMES_EX1_PLAYER_H


#include <SDL2/SDL_render.h>
#include "GameObject.h"

class Player : public GameObject{
    float speedX, speedY;
    float velX, velY;
public:
    float getVelX() const;

    float getVelY() const;

public:

    float getSpeedX() const;

    float getSpeedY() const;

private:
    SDL_Texture *playerTexture;
public:
    void setSpeedX(float speed);
    void setSpeedY(float speed);
    Player();
    Player(float x, float y);
    ~Player();
    float distanceBetweenPlayersX(Player *arg0);
    float distanceBetweenPlayersY(Player *arg0);
    //bool loadTexture(std::string path);
    void update(float secondSpeedX, float secondSpeedY);
    void start();

};


#endif //INC_2D_GAMES_EX1_PLAYER_H
