//
// Created by isi on 1/23/2023.
//

#ifndef FIRST3D_GAMEOBJECT_H
#define FIRST3D_GAMEOBJECT_H

#include "math.h"
#include "Cube.h"

class GameObject {
private:
    hmg::vect3f position;
    hmg::vect3f scale;

    Cube* cube = nullptr;

public:
    GameObject(hmg::vect3f position, hmg::vect3f scale);
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual ~GameObject();
};


#endif //FIRST3D_GAMEOBJECT_H
