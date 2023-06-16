//
// Created by isi on 1/24/2023.
//

#include <iostream>
#include "Gun.h"

Gun::Gun() {
}

void Gun::renderAim() {
    glPushMatrix();
    glTranslatef(aimPosition.x, aimPosition.y, aimPosition.z);
    glRotatef(-1.0 * angle, 0, 1, 0);
    glScalef(0.01, 0.01, 0.01);
    glBegin(GL_QUADS);
    //middle point
    glColor3f(1, 0, 0);
    glVertex3f(0.1, -0.1, 0.1);
    glVertex3f(0.1, 0.1, 0.1);
    glVertex3f(0.1, 0.1, -0.1);
    glVertex3f(0.1, -0.1, -0.1);
    glEnd();
    glPopMatrix();
}

void Gun::renderGun() {
    hmg::color baseColor{0.44,0.453,0.471};
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
    glTranslatef(aimPosition.x, aimPosition.y, aimPosition.z);
    glRotatef(-1.0 * angle, 0, 1, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.03, 0.1, 0.03);
    glBegin(GL_QUADS);
//    //face dessous
//    glColor3f(baseColor.r, baseColor.g, baseColor.g);
//    glTexCoord2f(0.0, 0.0);
//    glVertex3f(-1, -1, 1);
//    glTexCoord2f(0.0, 1.0);
//    glVertex3f(-1, -1, -1);
//    glTexCoord2f(1.0, 1.0);
//    glVertex3f(1, -1, -1);
//    glTexCoord2f(1.0, 0.0);
//    glVertex3f(1, -1, 1);
    //front (x +)
    glColor3f(baseColor.r * 0.9, baseColor.g * 0.9, baseColor.g * 0.9);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1, -1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1, 1, 1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, -1);
    //right (z +)
    glColor3f(baseColor.r * 0.8, baseColor.g * 0.8, baseColor.g * 0.8);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, 1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, 1);
    //left (z -)
    glColor3f(baseColor.r * 0.7, baseColor.g * 0.7, baseColor.g * 0.7);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, -1);
    //back (x -)
    glColor3f(baseColor.r * 0.6, baseColor.g * 0.6, baseColor.g * 0.6);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1, -1, 1);
    //top (z -)
    glColor3f(baseColor.r * 0.5, baseColor.g * 0.5, baseColor.g * 0.5);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, 1, 1);
    glEnd();
    glPopMatrix();
}

void Gun::update(hmg::vect3f gunPos, hmg::vect3f aimPos, float angle) {
    this->position = gunPos;
    this->aimPosition = aimPos;
    this->angle = angle;
}

void Gun::draw() {
    renderAim();
    if(isAiming == true){
        renderGun();
    }
}

void Gun::setPosition(const hmg::vect3f &position) {
    Gun::position = position;
}

void Gun::setAimPosition(const hmg::vect3f &aimPosition) {
    Gun::aimPosition = aimPosition;
}

void Gun::setAngle(float angle) {
    Gun::angle = angle;
}

void Gun::setIsAiming(bool isAiming){
    this->isAiming = isAiming;
}

bool Gun::getIsAiming() const {
    return this->isAiming;
}

Gun::~Gun() {

}
