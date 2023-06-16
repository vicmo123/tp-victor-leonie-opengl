//
// Created by isi on 1/26/2023.
//

#include "BulletManager.h"
#include "EnnemyManager.h"
#include "LifeManager.h"


void BulletManager::init() {
    this->nbBulletEnnemy = 0;
    this->nbBulletPlayer = 0;
    this->bulletsEnnemy = new Bullet * [200]();
    this->bulletsPlayer = new Bullet * [70]();
}

void BulletManager::update(std::vector<Cube*> walls, Cube* player, Cube* skybox, std::vector<Cube*> ennemiesPositions) {
    for (int i = 0; i < nbBulletEnnemy; i++) {
        bulletsEnnemy[i]->update(skybox);
        for (Cube* wall : walls) {
            if(manageCollisions(bulletsEnnemy[i]->getCube(), wall)){
                bulletsEnnemy[i]->isInCollision();
            }
        }
        if(manageCollisions(bulletsEnnemy[i]->getCube(), player)){
            bulletsEnnemy[i]->isInCollision();
            LifeManager::getInstance().looseOneLife();
        }
    }
    for (int i = 0; i < nbBulletPlayer; i++) {
        bulletsPlayer[i]->update(skybox);
        for (Cube* wall : walls) {
            if(manageCollisions(bulletsPlayer[i]->getCube(), wall)){
                bulletsPlayer[i]->isInCollision();
            }
        }
        for(Cube* ennemy : ennemiesPositions){
            if(manageCollisions(bulletsPlayer[i]->getCube(), ennemy)) {
                bulletsPlayer[i]->isInCollision();
                EnnemyManager::getInstance().deleteEnnemy(ennemy);
            }
        }
    }

    deleteInnactiveBullets();
}

void BulletManager::deleteInnactiveBullets() {
    for (int i = 0; i < this->nbBulletEnnemy; i++) {
        if (bulletsEnnemy[i]->getIsActive() == false) {
            delete this->bulletsEnnemy[i];
            this->bulletsEnnemy[i] = this->bulletsEnnemy[this->nbBulletEnnemy - 1];
            this->nbBulletEnnemy--;
            i--;
        }
    }
    for (int i = 0; i < this->nbBulletPlayer; i++) {
        if (bulletsPlayer[i]->getIsActive() == false) {
            delete this->bulletsPlayer[i];
            this->bulletsPlayer[i] = this->bulletsPlayer[this->nbBulletPlayer - 1];
            this->nbBulletPlayer--;
            i--;
        }
    }
}

bool BulletManager::manageCollisions(Cube *bullet, Cube *object) {
    if(abs(bullet->getPosition().x - object->getPosition().x) < bullet->getScale().x + object->getScale().x)
    {
        //check the Y axis
        if(abs(bullet->getPosition().y - object->getPosition().y) < bullet->getScale().y + object->getScale().y)
        {
            //check the Z axis
            if(abs(bullet->getPosition().z - object->getPosition().z) < bullet->getScale().z + object->getScale().z)
            {
                return true;
            }
        }
    }
    return false;
}

void BulletManager::spawnBullet(hmg::vect3f position, hmg::vect3f direction, BulletType type) {
    Bullet *bullet = new Bullet(position, direction, type);
    switch (type) {
        case ENNEMY:
            if (this->nbBulletEnnemy < 200) {
                this->bulletsEnnemy[this->nbBulletEnnemy] = bullet;
                this->nbBulletEnnemy++;
            }
            break;
        case PLAYER:
            if (this->nbBulletPlayer < 70) {
                this->bulletsPlayer[this->nbBulletPlayer] = bullet;
                this->nbBulletPlayer++;
            }
            break;
        default:
            std::cout << "Bullet not recognized. SpawnBullet function." << std::endl;
            break;
    }
}

void BulletManager::draw() {
    for (int i = 0; i < nbBulletEnnemy; i++) {
        bulletsEnnemy[i]->draw();
    }
    for (int i = 0; i < nbBulletPlayer; i++) {
        bulletsPlayer[i]->draw();
    }
}

BulletManager::~BulletManager() {
    for (int i = 0; i < nbBulletEnnemy; i++) {
        delete bulletsEnnemy[i];
    }
    for (int i = 0; i < nbBulletPlayer; i++) {
        delete bulletsPlayer[i];
    }
    delete bulletsEnnemy;
    delete bulletsPlayer;
}
