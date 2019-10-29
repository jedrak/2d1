//
// Created by jedra on 20.10.2019.
//

#include "Player.h"

#include <utility>
#include <iostream>

void Player::setSpeedX(float speedX) {
    Player::speedX = speedX;
}

void Player::setSpeedY(float speedY) {
    Player::speedY = speedY;
}

Player::Player() : GameObject(), speedX(0), speedY(0) {}

Player::Player(float x, float y) : GameObject(x, y), speedX(0), speedY(0){}

void Player::update(float secondSpeedX, float secondSpeedY) {
    float smooth = .5;
    velX = speedX * (1 - smooth) + velX * smooth;
    velY = speedY * (1 - smooth) + velY * smooth;
    this->setX(this->getX() + velX - secondSpeedX);
    this->setY(this->getY() + velY - secondSpeedY);
    //std::cout<< speedX <<" "<< speedX << std::endl;
}

void Player::start() {
    //    this->setX(0);
    //    this->setY(0);
    //    this->speedX = 0;
    //    this->speedY = 0;
}

float Player::getSpeedX() const {
    return speedX;
}

float Player::getSpeedY() const {
    return speedY;
}

float Player::distanceBetweenPlayersX(Player *arg0) {
    return this->getX() - arg0->getY();
}

float Player::distanceBetweenPlayersY(Player *arg0) {
    return this->getY() - arg0->getY();
}

Player::~Player() = default;




