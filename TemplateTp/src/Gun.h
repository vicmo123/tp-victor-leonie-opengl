//
// Created by isi on 1/24/2023.
//

#ifndef FIRST3D_GUN_H
#define FIRST3D_GUN_H


#include <vector>
#include "Cube.h"

class Gun {
private:
    bool isAiming = false;
    hmg::vect3f position;
    hmg::vect3f aimPosition;
    hmg::vect3f scale;
    float angle;
    void renderAim();
    void renderGun();
public:
    Gun();
    void update(hmg::vect3f gunPos, hmg::vect3f aimPos, float angle);
    void draw();
    void setPosition(const hmg::vect3f &position);
    void setAimPosition(const hmg::vect3f &aimPosition);
    void setAngle(float angle);
    void setIsAiming(bool isAiming);
    bool getIsAiming() const;
    ~Gun();
};


#endif //FIRST3D_GUN_H
