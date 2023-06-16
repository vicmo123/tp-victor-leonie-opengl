//
// Created by isi on 1/23/2023.
//

#ifndef FIRST3D_CITYMANAGER_H
#define FIRST3D_CITYMANAGER_H

#include <SDL2/SDL.h>
#include "math.h"
#include <vector>
#include "Cube.h"
#include "Camera.h"
#include "Singleton.h"
#include "opengl_util.h"
#include <GL/gl.h>

class CityManager : public Singleton<CityManager>{
private:
    GLuint idGrass, idRock, idBuildingWall, idBuildingRoof;
    hmg::vect3f startingPos;
    hmg::vect3f scale;
    std::vector<Cube*> map;
    std::vector<Cube*> walls;
    int desiredNumberOfTowers, towerWidth, towerHeight;
    int numMap = (int)0;
    int numWall = (int)0;

    void generateMap();
    void generateGrass(hmg::vect3f position);
    void generateWall(hmg::vect3f position);
    void generateTour(hmg::vect3f position, int height);
public:
    void init(hmg::vect3f startingPos, hmg::vect3f scale);
    void update();
    hmg::vect3f getFreeSpot();
    void draw();

    const std::vector<Cube *> &getWalls() const;

    bool checkCollision(Cube* a, Cube* b);

    virtual ~CityManager();
};


#endif //FIRST3D_CITYMANAGER_H
