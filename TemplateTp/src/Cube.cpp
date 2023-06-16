#include "Cube.h"


Cube::Cube(GLuint idTexture, hmg::vect3f position, hmg::vect3f scale, Direction _direction) {
    setPosition(position);
    setScale(scale);
    setIdTexture(idTexture);
    direction = _direction;
}

void Cube::update() {
    //todo
}

void Cube::draw() {
    glBindTexture(GL_TEXTURE_2D, idTexture);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glScalef(scale.x / 2.0, scale.y / 2.0, scale.z / 2.0);
    drawCube(direction);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Cube::drawCube(Direction direction) {
    glBegin(GL_QUADS);
    switch (direction) {
        case RIGHT:
            cubeRightCross();
            break;
        case LEFT:
            cubeLeftCross();
            break;
        case NO_DIRECTION:
            cubeBuilding();
            break;
    }
    glEnd();
}

void Cube::cubeRightCross() {
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(2.0 / 4.0, 0.0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(2.0 / 4.0, 1.0 / 3.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(3.0 / 4.0, 1.0 / 3.0);
    glVertex3f(1, -1, -1);
    glTexCoord2f(3.0 / 4.0, 0.0);
    glVertex3f(1, -1, 1);
    //front (x +)
    glTexCoord2f(2.0 / 4.0, 1.0 / 3.0);
    glVertex3f(1, -1, 1);
    glTexCoord2f(2.0 / 4.0, 2.0 / 3.0);
    glVertex3f(1, 1, 1);
    glTexCoord2f(3.0 / 4.0, 2.0 / 3.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(3.0 / 4.0, 1.0 / 3.0);
    glVertex3f(1, -1, -1);
    //right (z +)
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0 / 4.0, 1.0 / 3.0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0 / 4.0, 2.0 / 3.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(2.0 / 4.0, 2.0 / 3.0);
    glVertex3f(1, 1, 1);
    glTexCoord2f(2.0 / 4.0, 1.0 / 3.0);
    glVertex3f(1, -1, 1);
    //left (z -)
    glTexCoord2f(3.0 / 4.0, 1.0 / 3.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(3.0 / 4.0, 2.0 / 3.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(4.0 / 4.0, 2.0 / 3.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(4.0 / 4.0, 1.0 / 3.0);
    glVertex3f(1, -1, -1);
    //back (x -)
    glTexCoord2f(2.0 / 4.0, 1.0 / 3.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(2.0 / 4.0, 2.0 / 3.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(3.0 / 4.0, 2.0 / 3.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(3.0 / 4.0, 1.0 / 3.0);
    glVertex3f(-1, -1, 1);
    //top (z -)
    glTexCoord2f(2.0 / 4.0, 2.0 / 3.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(2.0 / 4.0, 3.0 / 3.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(3.0 / 4.0, 3.0 / 3.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(3.0 / 4.0, 2.0 / 3.0);
    glVertex3f(1, 1, 1);
}

void Cube::cubeLeftCross() {
    //face dessous
    glTexCoord2f(v4_1, 0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(v4_1, v3_1);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(v4_2, v3_1);
    glVertex3f(1, -1, 1);
    glTexCoord2f(v4_2, 0);
    glVertex3f(1, -1, -1);
    //face dessus
    glTexCoord2f(v4_1, v3_2);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(v4_1, v3_3);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(v4_2, v3_3);
    glVertex3f(1, 1, -1);
    glTexCoord2f(v4_2, v3_2);
    glVertex3f(1, 1, 1);
    //face droite
    glTexCoord2f(v4_2, v3_1);
    glVertex3f(1, -1, 1);
    glTexCoord2f(v4_2, v3_2);
    glVertex3f(1, 1, 1);
    glTexCoord2f(v4_3, v3_2);
    glVertex3f(1, 1, -1);
    glTexCoord2f(v4_3, v3_1);
    glVertex3f(1, -1, -1);
    //face gauche
    glTexCoord2f(0, v3_1);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(0, v3_2);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(v4_1, v3_2);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(v4_1, v3_1);
    glVertex3f(-1, -1, 1);
    //face devant
    glTexCoord2f(v4_1, v3_1);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(v4_1, v3_2);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(v4_2, v3_2);
    glVertex3f(1, 1, 1);
    glTexCoord2f(v4_2, v3_1);
    glVertex3f(1, -1, 1);
    //face derriere
    glTexCoord2f(v4_3, v3_1);
    glVertex3f(1, -1, -1);
    glTexCoord2f(v4_3, v3_2);
    glVertex3f(1, 1, -1);
    glTexCoord2f(v4_4, v3_2);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(v4_4, v3_1);
    glVertex3f(-1, -1, -1);
}

void Cube::cubeBuilding() {
    //face dessous
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, -1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, 1);
    //front (x +)
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1, -1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1, 1, 1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, -1);
    //right (z +)
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, 1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, 1);
    //left (z -)
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, -1);
    //back (x -)
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1, -1, 1);
    //top (z -)
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, 1, 1);
}

void Cube::setPosition(const hmg::vect3f &position) {
    Cube::position = position;
}

const hmg::vect3f &Cube::getPosition() const {
    return Cube::position;
}

void Cube::setScale(const hmg::vect3f &scale) {
    Cube::scale = scale;
}

const hmg::vect3f &Cube::getScale() const {
    return scale;
}

Cube::~Cube() {
    glDeleteTextures(1, &idTexture);
}

void Cube::setIdTexture(GLuint idTexture) {
    Cube::idTexture = idTexture;
}

