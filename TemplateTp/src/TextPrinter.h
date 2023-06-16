#ifndef MONPROJETSDL_TEXTPRINTER_H
#define MONPROJETSDL_TEXTPRINTER_H

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "gameDefine.h"
#include "math.h"
#include "Singleton.h"
#include "opengl_util.h"

#define frac1_10 1.0/10.0
#define frac2_10 2.0/10.0
#define frac3_10 3.0/10.0
#define frac4_10 4.0/10.0
#define frac5_10 5.0/10.0
#define frac6_10 6.0/10.0
#define frac7_10 7.0/10.0
#define frac8_10 8.0/10.0
#define frac9_10 9.0/10.0
#define frac10_10 10.0/10.0

class TextPrinter : public Singleton<TextPrinter>{
private:
    GLuint idTextureScore;
    GLuint idTextureNumbers;
    hmg::vect3f position;
    hmg::vect3f scale;
    float angle;
    int numberOfNumbers;
    std::string scoreValue;
    void renderScore();
    void renderNumbers();
    void renderSquare0();
    void renderSquare1();
    void renderSquare2();
    void renderSquare3();
    void renderSquare4();
    void renderSquare5();
    void renderSquare6();
    void renderSquare7();
    void renderSquare8();
    void renderSquare9();
public:
    void init();
    void update(hmg::vect3f positon, float angle, int score);
    void draw();
    void computeNumberOfNumbers(int scoreValue);
    ~TextPrinter();
};


#endif //MONPROJETSDL_TEXTPRINTER_H
