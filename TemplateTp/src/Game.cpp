#include "Game.h"
#include "Ennemy.h"
#include "LifeManager.h"

Game::Game() {
    bounds.right = WIDTH;
    bounds.bottom = HEIGHT;
    isRunning = true;
    clearColor = {0, 0, 0, 255};
}

void Game::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_WEBP);
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    window = SDL_CreateWindow("Hello OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, bounds.right, bounds.bottom, SDL_WINDOW_OPENGL /*| SDL_WINDOW_FULLSCREEN*/);
    //init opengl const
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (SDL_GL_SetSwapInterval(1)) {
        SDL_Log("Vsync present");
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    //init matrice
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, bounds.right / bounds.bottom, 0.01, 300);
    //mouse
    SDL_SetRelativeMouseMode(SDL_TRUE);
    //place to init all gameObject
    skybox = new Skybox();
    player = new Player(hmg::vect3f{0, 2, 0});
    cityManager->getInstance().init(hmg::vect3f{0, 0}, hmg::vect3f{100, 100});
    ennemyManager->getInstance().spawnEnnemies(25, {100, 100}, cityManager->getInstance().getWalls());
    scoreManager->getInstance();
    lifeManager->getInstance().init(player);
    textPrinter->getInstance().init();
    bulletManager->getInstance().init();
}

void Game::clear() {
    //place to delete all gameObject
    //delete textureManager;
    delete skybox;
    delete player;
    delete cityManager;
    delete ennemyManager;
    delete bulletManager;
    delete textPrinter;
    delete scoreManager;
    delete lifeManager;
    //delete sdl struct
    SDL_DestroyWindow(window);
    IMG_Quit();
    Mix_CloseAudio();
    SDL_Quit();
}

void Game::start() {
    while (isRunning) {
        update();
        cleanWindows();
        if(LifeManager::getInstance().loseGame()){
            isRunning = false;
        }
        draw();
        updateWindow();
    }
}

//<editor-fold desc="clean window update event update window">
void Game::cleanWindows() {
    //clear window
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Game::updateEvent() {
    SDL_PumpEvents();
    keyBordSate = SDL_GetKeyboardState(nullptr);
}

void Game::updateWindow() {
    cleanWindows();
}

//game operation
void Game::update() {
    //update modele from event
    updateEvent();
    if (keyBordSate[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
    //update objects
    cityManager->getInstance().update();
    player->update(&this->event, this->keyBordSate, this->xMouse, this->yMouse, cityManager->getInstance().getWalls());
    //player->update(this->keyBordSate, this->xMouse, this->yMouse, this->bounds);
    ennemyManager->getInstance().update(player->getPosition());
    //ennemy->update();
    bulletManager->getInstance().update(cityManager->getInstance().getWalls(), new Cube(0, this->player->getPosition(), hmg::vect3f {1, 2, 1}, Direction(0)), skybox->getCube(), EnnemyManager::getInstance().getEnnemiesPositions());
    textPrinter->getInstance().update(player->getTargetPosition(), player->getYaw(), scoreManager->getInstance().getScore());
    lifeManager->getInstance().update(player->getTargetPosition(), player->getYaw());
    //update modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Game::draw() {
    //set camera position(camera is in player)
    this->player->draw();
    //draw object on frame
    skybox->draw();
    cityManager->getInstance().draw();
    ennemyManager->getInstance().draw();
    textPrinter->getInstance().draw();
    bulletManager->getInstance().draw();
    lifeManager->getInstance().draw();
    //update screen
    glFlush();
    SDL_GL_SwapWindow(window);
}

