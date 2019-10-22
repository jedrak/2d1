//
// Created by jedra on 20.10.2019.
//

#include "Player.h"

#include <utility>

void Player::setSpeedX(int speedX) {
    Player::speedX = speedX;
}

void Player::setSpeedY(int speedY) {
    Player::speedY = speedY;
}

Player::Player() : GameObject(), speedX(0), speedY(0) {}

Player::Player(int x, int y) : GameObject(x, y), speedX(0), speedY(0){}

void Player::update() {
    this->setX(this->getX() + speedX );
    this->setY(this->getY() + speedY );
}

void Player::start() {
    //    this->setX(0);
    //    this->setY(0);
    //    this->speedX = 0;
    //    this->speedY = 0;
}

Player::~Player() {

}




