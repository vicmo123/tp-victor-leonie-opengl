#ifndef FIRST3D_CUBE_H
#define FIRST3D_CUBE_H

#include "math.h"
#include <GL/gl.h>
#include "opengl_util.h"
#include "Direction.h"
#include "gameDefine.h"

class Cube {
private:
    GLuint idTexture;
    Direction direction;
    hmg::vect3f position;
    hmg::vect3f scale;

    void drawCube(Direction direction);
    void cubeRightCross();
    void cubeLeftCross();
    void cubeBuilding();
public:
    void update();
    void draw();
    void setPosition(const hmg::vect3f &position);
    Cube(GLuint idTexture, hmg::vect3f position, hmg::vect3f scale, Direction _direction);
    const hmg::vect3f &getPosition() const;
    void setScale(const hmg::vect3f &scale);
    const hmg::vect3f &getScale() const;
    void setIdTexture(GLuint idTexture);
    virtual ~Cube();
};


#endif //FIRST3D_CUBE_H
