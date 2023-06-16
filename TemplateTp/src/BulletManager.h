//
// Created by isi on 1/26/2023.
//

#ifndef FIRST3D_BULLETMANAGER_H
#define FIRST3D_BULLETMANAGER_H


#include <vector>
#include "Bullet.h"
#include "Singleton.h"
#include "Ennemy.h"

class BulletManager : public Singleton<BulletManager> {
private:
    Bullet** bulletsEnnemy;
    int nbBulletEnnemy;
    Bullet** bulletsPlayer;
    int nbBulletPlayer;
public :
    void init();
    void spawnBullet(hmg::vect3f position, hmg::vect3f direction, BulletType type);
    void update(std::vector<Cube*> walls, Cube* player, Cube* skybox, std::vector<Cube*> ennemiesPositions);
    void draw();
    bool manageCollisions(Cube* bullet, Cube* object);
    void deleteInnactiveBullets();

    virtual ~BulletManager();

};

#endif //FIRST3D_BULLETMANAGER_H
