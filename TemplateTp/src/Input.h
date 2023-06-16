#ifndef SPACE_INVADERS_INPUT_H
#define SPACE_INVADERS_INPUT_H

#include <SDL2/SDL.h>
#include "Direction.h"
#include <iostream>
#include "Singleton.h"

enum KeyType{
    AWSD,
    ARROWS
};

class Input : public Singleton<Input>{
public:
    void init();
    Direction manageKeyboardEventsDirections(const Uint8* keyBordSate, KeyType keyType, Direction* possibleMovementDirections);
    bool checkSpaceBar();
    bool aimDownSight(SDL_Event* event);
    bool shootGun(SDL_Event* event);
};


#endif //SPACE_INVADERS_INPUT_H
