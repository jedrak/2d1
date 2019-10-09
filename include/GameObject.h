//
// Created by jedra on 08.10.2019.
//

#ifndef INC_2D_GAMES_EX1_GAMEOBJECT_H
#define INC_2D_GAMES_EX1_GAMEOBJECT_H


#include <string>

class GameObject {
private:
    int x, y;
    std::string pathToSprite;
public:
    GameObject();
    GameObject(int x, int y, std::string  pathToSprite);
    virtual void update() = 0;
    virtual void start() = 0;
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    const std::string &getPathToSprite() const;
    void setPathToSprite(const std::string &pathToSprite);
};


#endif //INC_2D_GAMES_EX1_GAMEOBJECT_H
