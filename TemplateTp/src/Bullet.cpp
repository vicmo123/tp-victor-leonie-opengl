//
// Created by isi on 1/24/2023.
//

#include "Bullet.h"

Bullet::Bullet(hmg::vect3f position, hmg::vect3f direction, BulletType type) : type(type) {
    this->position = position;
    this->scale = {.3, .3, .3};
    this->direction = direction;
    this->velocity = 1;
    this->animationTime = 5;
    lastTime = 0;
    this->texture = loadTexture("assets/sprites/mouth.png", false);
    cube = new Cube(texture, this->position, {scale.x, scale.y, scale.z}, LEFT);
}

hmg::vect3f Bullet::getPosition() {
    return hmg::vect3f();
}

void Bullet::draw() {
    cube->draw();
}

void Bullet::update(Cube* skybox) {
    move();
    this->isActive = checkIfActive(skybox);
}

void Bullet::move() {
    if (SDL_GetTicks() - lastTime >= animationTime) {
        hmg::vect3f unitDirection = direction.normalized();
        this->position += (unitDirection * velocity);
        this->cube->setPosition(position);
        lastTime = SDL_GetTicks();
    }
}

bool Bullet::checkIfActive(Cube *skybox) {
    //if is inside = collision so stays active
    if(abs(this->getPosition().x - skybox->getPosition().x) < this->getScale().x + skybox->getScale().x)
    {
        //check the Y axis
        if(abs(this->getPosition().y - skybox->getPosition().y) < this->getScale().y + skybox->getScale().y)
        {
            //check the Z axis
            if(abs(this->getPosition().z - skybox->getPosition().z) < this->getScale().z + skybox->getScale().z)
            {
                return true;
            }
        }
    }
    return false;
}

void Bullet::isInCollision() {
    this->isActive = false;
}

Bullet::~Bullet() {
    glDeleteTextures(1, &texture);
}

Cube *Bullet::getCube() const {
    return cube;
}

bool Bullet::getIsActive() const {
    return isActive;
}

const hmg::vect3f &Bullet::getScale() const {
    return scale;
}

void Bullet::setPosition(const hmg::vect3f &position) {
    Bullet::position = position;
}
