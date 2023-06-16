#include "TextPrinter.h"

void TextPrinter::renderScore() {
    glPushMatrix();
    glTranslatef(this->position.x, this->position.y + 0.04f, this->position.z);
    glRotatef(-1.0 * this->angle, 0, 1, 0);
    glTranslatef(0,  0,  - 0.018);
    glScalef(this->scale.x, this->scale.y, this->scale.z);
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(1.0,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(0.0,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderNumbers() {
    float zOffset = 0.0f;
    for (int i = 0; i < numberOfNumbers; ++i) {
        glPushMatrix();
        glTranslatef(this->position.x, this->position.y + 0.04f, this->position.z);
        glRotatef(-1.0  * this->angle, 0, 1, 0);
        glTranslatef(0, 0, zOffset);
        glScalef(this->scale.x, this->scale.y, this->scale.z);
        switch (this->scoreValue[i]) {
            case '0':
                renderSquare0();
                break;
            case '1':
                renderSquare1();
                break;
            case '2':
                renderSquare2();
                break;
            case '3':
                renderSquare3();
                break;
            case '4':
                renderSquare4();
                break;
            case '5':
                renderSquare5();
                break;
            case '6':
                renderSquare6();
                break;
            case '7':
                renderSquare7();
                break;
            case '8':
                renderSquare8();
                break;
            case '9':
                renderSquare9();
                break;
            default:
                break;
        }
        glPopMatrix();
        zOffset = (i + 1) * 0.018f;
    }
}

void TextPrinter::renderSquare0() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac1_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac1_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(0.0,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare1() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac2_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac2_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac1_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac1_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare2() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac3_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac3_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac2_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac2_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare3() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac4_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac4_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac3_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac3_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare4() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac5_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac5_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac4_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac4_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare5() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac6_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac6_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac5_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac5_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare6() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac7_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac7_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac6_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac6_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare7() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac8_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac8_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac7_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac7_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare8() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac9_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac9_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac8_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac8_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::renderSquare9() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
    glTexCoord2f(frac10_10,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(frac10_10,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(frac9_10,1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(frac9_10,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}

void TextPrinter::init() {
    this->idTextureNumbers = loadTexture("assets/sprites/numbers.png", true);
    this->idTextureScore = loadTexture("assets/sprites/score_txt.png", true);
    this->position = hmg::vect3f{0.0f, 0.0f, 0.0f};
    this->scale = hmg::vect3f{0.005, 0.01, 0.01};
    this->angle = 0.0f;
    this->numberOfNumbers = 0;
    this->scoreValue = "";
}

void TextPrinter::update(hmg::vect3f positon, float angle, int score) {
    this->position = positon;
    this->angle = angle;
    //score = "100";
    computeNumberOfNumbers(score);
}

void TextPrinter::draw() {
    glBindTexture(GL_TEXTURE_2D, idTextureScore);
    renderScore();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, idTextureNumbers);
    renderNumbers();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TextPrinter::computeNumberOfNumbers(int scoreValue) {
    std::string s = std::to_string(scoreValue);
    this->numberOfNumbers = s.size();
    this->scoreValue = s;
}

TextPrinter::~TextPrinter() {
    glDeleteTextures(1, &idTextureScore);
    glDeleteTextures(1, &idTextureNumbers);
}
