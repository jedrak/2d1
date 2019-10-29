//
// Created by jedra on 08.10.2019.
//

#ifndef INC_2D_GAMES_EX1_GAMEOBJECT_H
#define INC_2D_GAMES_EX1_GAMEOBJECT_H


#include <string>

class GameObject {
private:
    float x, y;
public:
    GameObject();
    GameObject(float x, float y);
    ~GameObject();
    //virtual void update() = 0;
    virtual void start() = 0;
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
};


#endif //INC_2D_GAMES_EX1_GAMEOBJECT_H
