//
// Created by isi on 1/23/2023.
//

#include "CityManager.h"


void CityManager::init(hmg::vect3f startingPos, hmg::vect3f scale) {
    this->startingPos = startingPos;
    this->scale = scale;
    desiredNumberOfTowers = 75;
    towerHeight = 6;
    towerWidth = 3;

    GLuint grassTexture  = loadTexture("assets/sprites/grass.jpg", false);
    idGrass = grassTexture;
    GLuint rockTexture  = loadTexture("assets/sprites/stone.jpg", true);
    idRock = rockTexture;
    GLuint buildingTexture = loadTexture("assets/sprites/building.png", true);
    idBuildingWall = buildingTexture;
    GLuint roofTexture  = loadTexture("assets/sprites/roof.png", true);
    idBuildingRoof = roofTexture;

    generateMap();
}

void CityManager::generateMap() {
    for (int x = -1; x < scale.x + 2; ++x) {
        for (int y = -1; y < scale.y + 2; ++y) {
            generateGrass(hmg::vect3f{static_cast<float>(x), -1.0, static_cast<float>(y)});
            if(x == -1 || y == -1 || x == scale.x + 1 || y == scale.y + 1){
                generateWall(hmg::vect3f{static_cast<float>(x), 0.0, static_cast<float>(y)});
                generateWall(hmg::vect3f{static_cast<float>(x), 1.0, static_cast<float>(y)});
            }
        }
    }

    for (int i = 0; i < desiredNumberOfTowers; ++i) {
        generateTour(this->getFreeSpot(), 6);
    }
}

void CityManager::generateGrass(hmg::vect3f position) {
    this->map.push_back(new Cube{idGrass, position, hmg::vect3f{1.0, 1.0, 1.0}, LEFT});
    numMap++;
}


void CityManager::generateWall(hmg::vect3f position) {
    this->walls.push_back(new Cube{idRock, position, hmg::vect3f{1.0, 1.0, 1.0}, LEFT});
    numWall++;
}

void CityManager::generateTour(hmg::vect3f position, int height) {
    for(int x = 0; x < towerWidth; ++x){
        for(int z = 0; z < towerWidth; ++z){
            for (int y = 0; y < towerHeight; ++y) {
                this->walls.push_back(new Cube{idBuildingWall, hmg::vect3f{position.x + x, position.y + y, position.z + z}, hmg::vect3f{1.0, 1.0, 1.0}, NO_DIRECTION});
                numWall++;
            }
        }
    }
}

void CityManager::update() {

}

void CityManager::draw() {
    for (Cube* cube : map) {
        cube->draw();
    }
    for (Cube* cube : walls) {
        cube->draw();
    }
}

hmg::vect3f CityManager::getFreeSpot() {
    bool spotFound = false;
    hmg::vect3f validSpot;

    //50 tries
    for (int i = 0; i < 50; i++)
    {
        float x = ceil(hmg::randomNumber::generateNumberF(3, scale.x - 3));
        float y = ceil(hmg::randomNumber::generateNumberF(3, scale.y - 3));

        hmg::vect3f tempSpot = hmg::vect3f{ x, 0.0,y};

        for (Cube* cube : walls) {
            Cube* tower = new Cube(0, tempSpot, hmg::vect3f{3.0, 6.0, 3.0}, static_cast<Direction>(0));
            if(checkCollision(tower, cube) == false){
                validSpot = tempSpot;
                spotFound = true;
                break;
            }
            delete tower;
        }

        if(spotFound){
            break;
        }
    }

    if(spotFound == true){
        return validSpot;
    }
    if(numWall == 0){
        return hmg::vect3f{scale.x/2, scale.z/2};
    }
    else{
        return hmg::vect3f::vectorZero();
    }
}

bool CityManager::checkCollision(Cube* a, Cube* b){

    //check the X axis
    if(abs(a->getPosition().x - b->getPosition().x) < a->getScale().x + b->getScale().x)
    {
        //check the Y axis
        if(abs(a->getPosition().y - b->getPosition().y) < a->getScale().y + b->getScale().y)
        {
            //check the Z axis
            if(abs(a->getPosition().z - b->getPosition().z) < a->getScale().z + b->getScale().z)
            {
                return true;
            }
        }
    }
    return false;
}


CityManager::~CityManager() {
    for (int i = 0; i < numMap; ++i) {
        delete map[i];
    }

    for (int i = 0; i < numWall; ++i) {
        delete walls[i];
    }

    glDeleteTextures(1,&idRock);
    glDeleteTextures(1,&idGrass);
    glDeleteTextures(1, &idBuildingWall);
    glDeleteTextures(1, &idBuildingRoof);
}

const std::vector<Cube *> &CityManager::getWalls() const {
    return walls;
}



