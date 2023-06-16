//
// Created by isi on 1/23/2023.
//

#ifndef FIRST3D_PLAYER_H
#define FIRST3D_PLAYER_H
#include "Camera.h"
#include "Cube.h"
#include "TextureManager.h"
#include "BulletManager.h"
#include "Gun.h"
#include "SoundManager.h"

class Player {
private:
    SoundManager* soundManager;
    Input* input;
    Direction* possibleMovementDirections;
    Camera* camera;
    Gun* gun;
    int shootTime;
    Uint32 lastShoot = SDL_GetTicks();
    int deltaTime = 50;
public:
    Player(hmg::vect3f position);
    void draw();
    void update(SDL_Event* event, const Uint8* keyBordSate, int& xMouse, int& yMouse, std::vector<Cube*> walls);
    std::pair<bool, Cube*> manageCollision(std::vector<Cube*> walls);
    bool checkCollision(Cube* a, Cube* b);
    void slideWall(Direction input, hmg::vect3f oldPosition, Cube* collidedWall);
    void aimDownSight(bool b);
    hmg::vect3f getPosition();
    hmg::vect3f getTargetPosition() const;
    float getYaw();
    Direction findSide(Cube* collidedWall);
    void shoot();
    virtual ~Player();
};


#endif //FIRST3D_PLAYER_H
