#include "ScoreManager.h"

int ScoreManager::getScore() {
    return this->score;
}

void ScoreManager::addPoints(int pointsToAdd) {
    this->score += pointsToAdd;
}
