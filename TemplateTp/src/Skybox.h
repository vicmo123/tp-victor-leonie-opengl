//
// Created by isi on 1/25/2023.
//

#ifndef FIRST3D_SKYBOX_H
#define FIRST3D_SKYBOX_H

#include <GL/gl.h>
#include "math.h"
#include "Cube.h"

class Skybox {
private :
    Cube* cube;
    GLuint texture;
public:
    Skybox();
    void draw();
    Cube *getCube() const;
    virtual ~Skybox();
};


#endif //FIRST3D_SKYBOX_H
