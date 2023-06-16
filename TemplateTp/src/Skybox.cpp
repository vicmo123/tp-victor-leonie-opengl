//
// Created by isi on 1/25/2023.
//

#include "Skybox.h"
#include "opengl_util.h"

Skybox::Skybox() {
    texture = loadTexture("assets/sprites/skyboxUpdated1.png", true);
    this->cube = new Cube(texture, {51,25,51}, {300,300,300}, LEFT);
}

void Skybox::draw() {
    cube->draw();
}


Skybox::~Skybox() {
    glDeleteTextures(1, &texture);
}

Cube *Skybox::getCube() const {
    return cube;
}
