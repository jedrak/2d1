//
// Created by jedra on 08.10.2019.
//

#include "GameObject.h"

#include <utility>

GameObject::GameObject(int x, int y) : x(x), y(y){}

GameObject::GameObject() : x(0), y(0){}

int GameObject::getX() const {
    return x;
}

int GameObject::getY() const {
    return y;
}

void GameObject::setY(int y) {
    GameObject::y = y;
}

void GameObject::setX(int x) {
    GameObject::x = x;
}

GameObject::~GameObject() = default;

