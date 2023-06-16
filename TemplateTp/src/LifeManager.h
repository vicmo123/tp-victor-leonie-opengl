//
// Created by isi on 1/27/2023.
//

#ifndef FIRST3D_LIFEMANAGER_H
#define FIRST3D_LIFEMANAGER_H


#include "Singleton.h"
#include "Player.h"

class LifeManager : public Singleton<LifeManager>{
private:
    GLuint idTexHeart;
    hmg::vect3f position;
    hmg::vect3f scale;
    float angle;
    int nbLifes;
    bool gameOver;
    Player* player;
    void renderSquare();
public:
    void init(Player* player);
    void update(hmg::vect3f position, float angle);
    void draw();
    void looseOneLife();
    bool loseGame();

    virtual ~LifeManager();
};


#endif //FIRST3D_LIFEMANAGER_H
