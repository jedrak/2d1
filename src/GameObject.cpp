//
// Created by jedra on 08.10.2019.
//

#include "GameObject.h"


GameObject::GameObject(float x, float y) : x(x), y(y){}

GameObject::GameObject() : x(0), y(0){}

float GameObject::getX() const {
    return x;
}

float GameObject::getY() const {
    return y;
}

void GameObject::setY(float y) {
    GameObject::y = y;
}

void GameObject::setX(float x) {
    GameObject::x = x;
}

GameObject::~GameObject() = default;

