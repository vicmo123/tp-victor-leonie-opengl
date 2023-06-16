//
// Created by isi on 1/24/2023.
//

#include "Ennemy.h"

Ennemy::Ennemy() {
    //faceTexture = loadTexture("assets/sprites/cactusFace.png", false);
    cactusTexture = loadTexture("assets/sprites/cactus.png", true);
    oeil = loadTexture("assets/sprites/oeil.png", true);
    mouth = loadTexture("assets/sprites/mouth.png", true);
    position = {0, 0, 0};
    scale = {1, 1, 1};
    this->speedRotation = 0.015;
    this->angle = 0;
    this->color = {255, 255, 255};
    params = gluNewQuadric();
    this->beforeShootTime = 3000;
    this->beforeBlinkTime = 3000;
    this-> eyesOpen = true;
    this->eyeZ = 1.5;
    lastTime = SDL_GetTicks();
    blinkTime = SDL_GetTicks();
    lastTimeEye = SDL_GetTicks();
}


void Ennemy::draw() {
    glBindTexture(GL_TEXTURE_2D, cactusTexture);

    glPushMatrix();
    glColor3ub(color.r, color.g, color.b);
    glTranslatef(position.x, position.y, position.z);
    glRotated(angle, 0, 1, 0);

    drawTigeCentrale();
    drawBrasDroit();
    drawBrasGauche();
    drawFace();
    glPopMatrix();
}

void Ennemy::update() {

}

void Ennemy::shoot() {
    if (SDL_GetTicks() - lastTime >= beforeShootTime) {
        float angleRadians = angle * M_PI / 180.0;
        hmg::vect3f direction = {sin(angleRadians), 0, cos(angleRadians)};
        BulletManager::getInstance().spawnBullet(this->position, direction, ENNEMY);
        lastTime = SDL_GetTicks();
    }
}

void Ennemy::setPosition(const hmg::vect3f &position) {
    Ennemy::position = position;
}

const hmg::vect3f &Ennemy::getPosition() const {
    return position;
}

void Ennemy::setAngle(float angle) {
    Ennemy::angle = angle;
}

float Ennemy::getAngle() const {
    return angle;
}

void Ennemy::drawTigeCentrale() {
    glPushMatrix();
    glRotated(-90, 1, 0, 0);
    glTranslatef(0, 0, -0.5);
    gluCylinder(params, .2, .2, 3, 10, 5);
    glPopMatrix();

    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricTexture(params, GL_TRUE);

    //boule
    glPushMatrix();
    glTranslatef(0, 2.5, 0);
    glRotated(-90, 1, 0, 0);
    gluSphere(params, .2, 20, 20);
    glPopMatrix();
}

void Ennemy::drawBrasDroit() {
//tige droite
    glPushMatrix();
    glTranslatef(.18, 1, 0);
    glRotated(90, 0, 1, 0);
    gluCylinder(params, .1, .1, .2, 10, 5);
    glTranslatef(0, 0, .2);
    gluSphere(params, .1, 20, 20);
    glTranslatef(0, 0, .02);
    glRotated(-90, 1, 0, 0);
    gluCylinder(params, .1, .1, .6, 10, 5);
    glTranslatef(0, 0, .6);
    gluSphere(params, .1, 20, 20);
    glPopMatrix();
}

void Ennemy::drawBrasGauche() {
//tige gauche
    glPushMatrix();
    glTranslatef(-.18, 1.5, 0);
    glRotated(-90, 0, 1, 0);
    gluCylinder(params, .1, .1, .2, 10, 5);
    glTranslatef(0, 0, .2);
    gluSphere(params, .1, 20, 20);
    glTranslatef(0, 0, .02);
    glRotated(-90, 1, 0, 0);
    gluCylinder(params, .1, .1, .45, 10, 5);
    glTranslatef(0, 0, .45);
    gluSphere(params, .1, 20, 20);
    glPopMatrix();
}

void Ennemy::drawFace() {
//Face
    //oeil droit
    glBindTexture(GL_TEXTURE_2D, oeil);
    gluQuadricTexture(params, GL_TRUE);
    glPushMatrix();
    glTranslatef(.08, 1.6, .2);
    glRotated(-90, 1, 0, 0);
    glRotated(45, 0, 0, 1);
    if (SDL_GetTicks() - blinkTime > deltaTime) {
        if (SDL_GetTicks() - blinkTime >= beforeBlinkTime) {
            if(shutEye == false){
                shutEye = true;
            }
            blinkTime = SDL_GetTicks() ;
        }
    }
    blinkEyes();

    glScaled(1, 1, eyeZ);
    gluSphere(params, .05, 20, 20);
    glPopMatrix();
//oeil gauche
    glPushMatrix();
    glTranslatef(-.08, 1.6, .2);
    glRotated(-90, 1, 0, 0);
    glRotated(45, 0, 0, 1);
    //fermer l'oeil en modifiant l'axe des z
    glScaled(1, 1, eyeZ);
    gluSphere(params, .05, 20, 20);
    glPopMatrix();

    //bouche
    glBindTexture(GL_TEXTURE_2D, mouth);
    gluQuadricTexture(params, GL_TRUE);
    glPushMatrix();
    glTranslatef(0, 1.4, .2);
    glRotated(-90, 1, 0, 0);
    glRotated(45, 0, 0, 1);
    glScaled(1, 1.5, 1);
    gluSphere(params, .03, 20, 20);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);

    //ancienne face, garder en cas de probleme :
//    glBindTexture(GL_TEXTURE_2D, faceTexture);
//    GLUquadric *faceSpot = gluNewQuadric();
//    gluQuadricTexture(faceSpot, GL_TRUE);
//    glPushMatrix();
//    glColor3ub(color.r, color.g, color.b);
//    glTranslatef(position.x, position.y + 1.6, position.z);
//    glRotated(-90, 1, 0, 0);
//    glTranslatef(0, 0, 0 - 0.5);
//    gluCylinder(params, .205, .205, .7, 10, 5);
//    glPopMatrix();

}

float Ennemy::getSpeedRotation() const {
    return speedRotation;
}

Ennemy::~Ennemy() {
    gluDeleteQuadric(params);
    glDeleteTextures(1, &cactusTexture);
    glDeleteTextures(1, &oeil);
    glDeleteTextures(1, &mouth);
    //glDeleteTextures(1, &faceTexture);
}

float Ennemy::blinkEyes() {
    if(shutEye){
        if(eyesOpen && eyeZ > 0.1){
            eyeZ-= 0.1;
        }else if(!eyesOpen && eyeZ < 1.5){
            eyeZ+= 0.1;
        }
    }

    if(eyeZ >= 1.5){
        eyesOpen = true;
        shutEye = false;
    }
    else if(eyeZ < 0.1){
        eyesOpen = false;
    }
}
