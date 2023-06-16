//
// Created by isi on 1/24/2023.
//

#ifndef FIRST3D_ENNEMY_H
#define FIRST3D_ENNEMY_H

#include "Cube.h"
#include "BulletManager.h"

class Ennemy {
private:
    GLuint cactusTexture, oeil, mouth;
    //GLuint faceTexture;
    hmg::vect3f scale, position;
    float speedRotation, angle;
    hmg::color color;
    GLUquadric *params;
    float beforeShootTime, beforeBlinkTime,  eyeZ ;
    GLuint lastTime, lastTimeEye,  blinkTime;
    bool eyesOpen;
    bool shutEye = false;
    int deltaTime = 50;

    void drawTigeCentrale();

    void drawBrasDroit();

    void drawBrasGauche();

    void drawFace();

    float blinkEyesOpen();

    float blinkEyes();

public:
    Ennemy();

    void draw();

    void update();

    void shoot();

    const hmg::vect3f &getPosition() const;

    void setAngle(float angle);

    float getAngle() const;

    float getSpeedRotation() const;

    void setPosition(const hmg::vect3f &position);

    virtual ~Ennemy();
};


#endif //FIRST3D_ENNEMY_H
