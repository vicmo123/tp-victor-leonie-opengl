//
// Created by isi on 1/24/2023.
//

#include "EnnemyManager.h"
#include "ScoreManager.h"

const std::vector<Ennemy *> &EnnemyManager::getEnnemies() const {
    return ennemies;
}

void
EnnemyManager::spawnEnnemies(int nbEnnemies, hmg::bounds2D worldLimits, std::vector<Cube *> walls) {
    this->walls = walls;

    for (int i = 0; i < nbEnnemies; i++) {
        Ennemy *ennemy = new Ennemy();

        hmg::vect3f spot = getFreeSpot(worldLimits);
        ennemy->setPosition({spot.x, 0, spot.z});
        float angle = hmg::randomNumber::generateNumberF(0, 360);
        ennemy->setAngle(angle);
        ennemies.push_back(ennemy);
    }

    updateListEnnemisPositions();
}

void EnnemyManager::update(hmg::vect3f playerPos) {

    for (auto ennemy: ennemies) {
        hmg::vect3f ennemyPos = ennemy->getPosition();

        float angleEnnemy = ennemy->getAngle();
        float angleEnnemiInRadians = angleEnnemy * M_PI / 180.0;
        //vecteur unitaire de l'ennemi pour connaitre sa direction
        hmg::vect3f ennemyRotation = {sin(angleEnnemiInRadians), 0, cos(angleEnnemiInRadians)};
        //vecteur de l'ennemi vers le joueur
        hmg::vect3f toPlayer = {playerPos.x - ennemyPos.x, 0, playerPos.z - ennemyPos.z};
        //calculer la difference d'angle a appliquer pour que l'ennemi regarde le joueur
        float newAngle = hmg::vect3f::signedAngle(ennemyRotation, toPlayer, {0, 1, 0});
        //appliquer cette difference
        angleEnnemy += newAngle * ennemy->getSpeedRotation();

        //calculer la distance entre l'ennemi et le player
        float distanceX = playerPos.x - ennemyPos.x;
        float distanceZ = playerPos.z - ennemyPos.z;
        hmg::vect3f distance = {distanceX, 0, distanceZ};
        if (hmg::vect3f::magnitude(&distance) <= 20) {
            ennemy->shoot();
        }

        ennemy->setAngle(angleEnnemy);
    }
}

void EnnemyManager::deleteEnnemy(Cube* cube) {
    for (int i = 0; i < ennemies.size(); i++) {
        if (ennemies[i]->getPosition().x == cube->getPosition().x && ennemies[i]->getPosition().y == cube->getPosition().y) {
            ennemies.erase(ennemies.begin() + i);
            break;
        }
    }
    updateListEnnemisPositions();
    ScoreManager::getInstance().addPoints(10);
}

void EnnemyManager::draw() {
    for (auto ennemy: ennemies) {
        ennemy->draw();
    }
}

hmg::vect3f EnnemyManager::getFreeSpot(hmg::bounds2D worldLimits) {
    bool spotFound = false;
    hmg::vect3f validSpot;

    //50 tries
    for (int i = 0; i < 50; i++) {
        float x = ceil(hmg::randomNumber::generateNumberF(2, 100 - 2));
        float z = ceil(hmg::randomNumber::generateNumberF(2, 100 - 2));

        hmg::vect3f tempSpot = hmg::vect3f{x, 0.0f, z};

        for (Cube *cube: this->walls) {
            SDL_FRect r2{static_cast<float>(cube->getPosition().x - 0.5f),
                         static_cast<float>(cube->getPosition().z - 0.5f), static_cast<float>(3),
                         static_cast<float>(3)};
            SDL_FRect r1{static_cast<float>(x - 0.5f), static_cast<float>(z - 0.5f), 1.0,
                         1.0};
            if (SDL_IntersectFRect(&r1, &r2, NULL) == false) {
                validSpot = tempSpot;
                spotFound = true;
                break;
            }
        }
        if (spotFound) {
            break;
        }
    }

    if (spotFound == true) {
        return validSpot;
    } else {
        return hmg::vect3f::vectorZero();
    }
}

EnnemyManager::~EnnemyManager() {
    for (auto wall: walls) {
        delete wall;
    }
    for (auto ennemy: ennemies) {
        delete ennemy;
    }
}

const vector<Cube *> &EnnemyManager::getEnnemiesPositions() const {
    return ennemiesPositions;
}

void EnnemyManager::updateListEnnemisPositions() {
    ennemiesPositions.clear();

    for (int i = 0; i < ennemies.size(); i++) {
        Cube *cube = new Cube(0, ennemies[i]->getPosition(), {.6, 2, .6}, RIGHT);
        ennemiesPositions.push_back(cube);
    }
}
