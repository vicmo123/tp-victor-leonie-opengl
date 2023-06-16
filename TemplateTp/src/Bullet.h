//
// Created by isi on 1/24/2023.
//

#ifndef FIRST3D_BULLET_H
#define FIRST3D_BULLET_H


#include <chrono>
#include "math.h"
#include "Cube.h"
#include "GenericTimer.h"
#include "BulletType.h"

using namespace std;
class Bullet {
private:
    BulletType type;
    hmg::vect3f position, direction,scale;
    Cube *cube;
    float velocity, animationTime;
    int lastTime;
    GLuint texture;
    bool isActive = true;
public:
    Bullet(hmg::vect3f position, hmg::vect3f direction,  BulletType type);
    hmg::vect3f getPosition();
    void setPosition(const hmg::vect3f &position);
    const hmg::vect3f &getScale() const;
    void draw();
    void update(Cube* skybox);
    void move();
    bool checkIfActive(Cube* skybox);
    void isInCollision();
    Cube *getCube() const;
    bool getIsActive() const;
    virtual ~Bullet();
};


#endif //FIRST3D_BULLET_H
