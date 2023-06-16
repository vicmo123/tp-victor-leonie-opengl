#ifndef MONPROJETSDL_GAME_H
#define MONPROJETSDL_GAME_H
#include "gameDefine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "math.h"
#include "Camera.h"
#include "CityManager.h"
#include "Player.h"
#include "Ennemy.h"
#include "EnnemyManager.h"
#include "Skybox.h"
#include "TextPrinter.h"
#include "ScoreManager.h"
#include "LifeManager.h"

class Game {
private:
    SDL_Window* window;
    hmg::bounds2D bounds;
    SDL_Color clearColor;
    bool isRunning;

    //event prop
    SDL_Event event;
    const Uint8* keyBordSate;
    int xMouse,yMouse;

    //GameObjects
    Player* player;
    Skybox* skybox;
    CityManager* cityManager;
    EnnemyManager* ennemyManager;
    BulletManager*  bulletManager;
    ScoreManager* scoreManager;
    LifeManager* lifeManager;
    TextPrinter* textPrinter;
public:
    Game();
    void init();
    void start();
    void clear();
private:
    //methode into loopgame
    void cleanWindows();
    void updateEvent();
    void update();
    void draw();
    void updateWindow();
};
#endif //MONPROJETSDL_GAME_H
