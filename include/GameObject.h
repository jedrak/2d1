//
// Created by jedra on 08.10.2019.
//

#ifndef INC_2D_GAMES_EX1_GAMEOBJECT_H
#define INC_2D_GAMES_EX1_GAMEOBJECT_H


#include <string>

class GameObject {
private:
    int x, y;
public:
    GameObject();
    GameObject(int x, int y);
    ~GameObject();
    virtual void update() = 0;
    virtual void start() = 0;
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
};


#endif //INC_2D_GAMES_EX1_GAMEOBJECT_H
