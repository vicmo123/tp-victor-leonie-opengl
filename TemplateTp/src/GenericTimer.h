//
// Created by isi on 1/26/2023.
//

#ifndef FIRST3D_GENERICTIMER_H
#define FIRST3D_GENERICTIMER_H

#include <chrono>

using namespace std;

//	Generic type could be chrono::milliseconds or chrono::microseconds
template<typename T = chrono::milliseconds>
class GenericTimer {
private:
    uint64_t duration;        //	duration in milliseconds or microseconds
    uint64_t nextEvent;        //	next timestamp for event

public:
    GenericTimer(uint64_t duration) {
        this->duration = duration;
        this->nextEvent =
                chrono::duration_cast<T>(chrono::high_resolution_clock::now().time_since_epoch()).count() + duration;
    }

    bool isReady() {
        bool ready = false;

        uint64_t now = (uint64_t) chrono::duration_cast<T>(
                chrono::high_resolution_clock::now().time_since_epoch()).count();

        if (now >= this->nextEvent) {
            this->nextEvent = now + this->duration;
            ready = true;
        }

        return ready;
    }
};


//	Generic type could be chrono::milliseconds or chrono::microseconds
template<class T = chrono::milliseconds>
class GenericTicker {
private:
    uint64_t last;

public:
    GenericTicker() {
        this->reset();
    }

    void reset() {
        this->last = (uint64_t) chrono::duration_cast<T>(
                chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

    uint64_t getElapsedTime() {
        uint64_t now = (uint64_t) chrono::duration_cast<T>(
                chrono::high_resolution_clock::now().time_since_epoch()).count();
        uint64_t ticks = now - this->last;
        this->last = now;
        return ticks;
    }
};

#endif //FIRST3D_GENERICTIMER_H
