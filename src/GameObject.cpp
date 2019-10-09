//
// Created by jedra on 08.10.2019.
//

#include "GameObject.h"

#include <utility>

GameObject::GameObject(int x, int y, std::string  pathToSprite) : x(x), y(y), pathToSprite(std::move(pathToSprite)){}

GameObject::GameObject() : x(0), y(0), pathToSprite(" "){}

int GameObject::getX() const {
    return x;
}

int GameObject::getY() const {
    return y;
}

void GameObject::setY(int y) {
    GameObject::y = y;
}

const std::string &GameObject::getPathToSprite() const {
    return pathToSprite;
}

void GameObject::setPathToSprite(const std::string &pathToSprite) {
    GameObject::pathToSprite = pathToSprite;
}

void GameObject::setX(int x) {
    GameObject::x = x;
}

