//
// Created by isi on 1/23/2023.
//

#include "GameObject.h"

GameObject::GameObject(hmg::vect3f position, hmg::vect3f scale) {
    this->position = position;
    this->scale = scale;
}

GameObject::~GameObject() {
    delete this->cube;
}
