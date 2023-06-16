//
// Created by isi on 1/27/2023.
//

#include "LifeManager.h"

void LifeManager::init(Player *player) {
    this->idTexHeart = loadTexture("assets/sprites/heart.png", true);
    this->nbLifes = 3;
    this->gameOver = false;
    this->player = player;
    this->position = hmg::vect3f{0.0f, 0.0f, 0.0f};
    this->scale = hmg::vect3f{0.005, 0.01, 0.01};
}

void LifeManager::looseOneLife() {
    if (nbLifes > 1) {
        this->nbLifes--;
    } else if (this->nbLifes == 1) {
        gameOver = true;
        loseGame();
    }
}

void LifeManager::renderSquare() {
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(1.0,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(0.0,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
}

void LifeManager::update(hmg::vect3f position, float angle) {
    this->position = position;
    this->angle = angle;
}

void LifeManager::draw() {
    float zOffSet = - 0.018;
    for (int i = 0; i < nbLifes; ++i) {
        glBindTexture(GL_TEXTURE_2D, idTexHeart);
        glPushMatrix();
        glTranslatef(this->position.x, this->position.y + 0.06f, this->position.z);
        glRotatef(-1.0 * this->angle, 0, 1, 0);
        glTranslatef(0,  0,  zOffSet);
        glScalef(this->scale.x, this->scale.y, this->scale.z);
        renderSquare();
        glPopMatrix();
        zOffSet += 0.018;
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

bool LifeManager::loseGame() {
    return this->gameOver;
}

LifeManager::~LifeManager() {
    delete player;
    glDeleteTextures(1, &idTexHeart);
}


