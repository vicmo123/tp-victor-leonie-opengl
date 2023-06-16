//
// Created by isi on 1/23/2023.
//

#include "Player.h"

Player::Player(hmg::vect3f position) {
    this->soundManager->getInstance().init();
    this->input->getInstance().init();
    this->possibleMovementDirections = new Direction[4]{LEFT, RIGHT, FORWARD, BACKWARD};
    this->camera = new Camera(position, false);
    this->gun = new Gun();
    this->shootTime = 350;
    this->lastShoot = SDL_GetTicks();
}

void Player::update(SDL_Event* event, const Uint8 *keyBordSate, int &xMouse, int &yMouse, std::vector<Cube*> walls) {
    //Keyboard event
    auto input = this->input->getInstance().manageKeyboardEventsDirections(keyBordSate, AWSD, this->possibleMovementDirections);
    hmg::vect3f oldPos = this->getPosition();
    this->camera->processKeyboard(input, 0.2);
    if (this->manageCollision(walls).first){
        this->camera->setPosition(oldPos);
        //slideWall(input, oldPos, this->manageCollision(walls).second);
    }
    if(this->input->getInstance().checkSpaceBar()){
        shoot();
    }
    //mouse events
    while(SDL_PollEvent(event)){
        switch(event->type){
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "click" << std::endl;
                this->aimDownSight(true);
                break;
            case SDL_MOUSEBUTTONUP:
                std::cout << "click" << std::endl;
                this->aimDownSight(false);
                break;
        }
    }
    SDL_GetRelativeMouseState(&xMouse, &yMouse);
    this->camera->processMouseMovement(xMouse, yMouse);
    //set and update gun
    this->gun->update(this->camera->getPosition() ,this->camera->getTargetPosition(), this->camera->getYaw());
}

void Player::draw() {
    this->camera->setView();
    this->gun->draw();
}

std::pair<bool, Cube*> Player::manageCollision(std::vector<Cube*> walls) {
    bool isCollision = false;
    Cube* collidedWall = nullptr;
    Cube* player = new Cube(0, this->camera->getPosition(), hmg::vect3f {0.1, 1.0, 0.1}, static_cast<Direction>(0));
    for (Cube* wall : walls) {
        if(checkCollision(player, wall)){
            isCollision = true;
            collidedWall = wall;
        }
    }
    delete player;
    return std::make_pair(isCollision, collidedWall);
}

hmg::vect3f Player::getPosition() {
    return this->camera->getPosition();
}

void Player::shoot() {
    if (SDL_GetTicks() - lastShoot > deltaTime) {
        if (SDL_GetTicks() - lastShoot >= shootTime) {
            soundManager->getInstance().playWav(1, 0, 0);
            BulletManager::getInstance().spawnBullet(this->getPosition(), camera->getFront(), PLAYER);
            lastShoot = SDL_GetTicks();
        }
    }
}

bool Player::checkCollision(Cube* a, Cube* b){
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

float Player::getYaw() {
    return this->camera->getYaw();
}

void Player::slideWall(Direction input, hmg::vect3f oldPosition, Cube* collidedWall) {
    //Direction hittenSide = findSide(collidedWall);
    if(input == FORWARD && fabs(this->camera->getFront().z) > fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{this->getPosition().x, this->getPosition().y, oldPosition.z});
    }
    else if(input == FORWARD && fabs(this->camera->getFront().z) < fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{oldPosition.x, this->getPosition().y, this->getPosition().z});
    }
    else if(input == BACKWARD && fabs(this->camera->getFront().z) > fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{this->getPosition().x, this->getPosition().y, oldPosition.z});
    }
    else if(input == BACKWARD && fabs(this->camera->getFront().z) < fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{oldPosition.x, this->getPosition().y, this->getPosition().z});
    }
    if(input == RIGHT && fabs(this->camera->getFront().z) < fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{this->getPosition().x, this->getPosition().y, oldPosition.z});
    }
    else if(input == RIGHT && fabs(this->camera->getFront().z) > fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{oldPosition.x, this->getPosition().y, this->getPosition().z});
    }
    else if(input == LEFT && fabs(this->camera->getFront().z) < fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{this->getPosition().x, this->getPosition().y, oldPosition.z});
    }
    else if(input == LEFT && fabs(this->camera->getFront().z) > fabs(this->camera->getFront().x)){
        this->camera->setPosition(hmg::vect3f{oldPosition.x, this->getPosition().y, this->getPosition().z});
    }
}

void Player::aimDownSight(bool b) {
    this->gun->setIsAiming(b);
}

hmg::vect3f Player::getTargetPosition() const {
    return camera->getTargetPosition();
}

Direction Player::findSide(Cube* collidedWall) {
    float newAngle = hmg::vect3f::signedAngle({cos(0.0f), 0, sin(0.0f)}, {this->getPosition().x - collidedWall->getPosition().x,0.0f, this->getPosition().z - collidedWall->getPosition().z}, {0,1,0});
    Direction hitSide = NO_DIRECTION;
    //this sucks but works ok
    if(newAngle > -20.0f && newAngle < 70.0f){
        //std::cout << "+x" << std::endl;
        hitSide = LEFT;
    }
    if(newAngle > 70.0f && newAngle < 135.0f) {
        //std::cout << "-z" << std::endl;
        hitSide = BACKWARD;
    }
    if ((newAngle > 135.0f && newAngle <= 180.0f) || (newAngle > -180.0f && newAngle < -120.0f)){
        //std::cout << "-x" << std::endl;
        hitSide = RIGHT;
    }
    if ((newAngle > -119.0f && newAngle < -20.0f)){
        //std::cout << "+z" << std::endl;
        hitSide = FORWARD;
    }
    return hitSide;
}

Player::~Player() {
    delete input;
    delete soundManager;
    delete possibleMovementDirections;
    delete camera;
    delete gun;
}

