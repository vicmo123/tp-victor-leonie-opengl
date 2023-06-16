//
// Created by isi on 1/24/2023.
//

#ifndef FIRST3D_ENNEMYMANAGER_H
#define FIRST3D_ENNEMYMANAGER_H

#include "math.h"
#include "Ennemy.h"
#include <SDL2/SDL.h>
#include "Singleton.h"
#include "Player.h"

class EnnemyManager : public Singleton<EnnemyManager> {
private :
    std::vector<Ennemy *> ennemies;
    std::vector<Cube *> ennemiesPositions;
    std::vector<Cube *> walls;

    void updateListEnnemisPositions();
public :
    void spawnEnnemies(int nbEnnemies, hmg::bounds2D worldLimits, std::vector<Cube *> walls);

    hmg::vect3f getFreeSpot(hmg::bounds2D worldLimits);

    void update(hmg::vect3f playerPos);

    const vector<Cube *> &getEnnemiesPositions() const;

    void deleteEnnemy(Cube* cube);

    const std::vector<Ennemy *> &getEnnemies() const;

    void draw();

    virtual ~EnnemyManager();
};


#endif //FIRST3D_ENNEMYMANAGER_H
