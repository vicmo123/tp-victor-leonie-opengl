#ifndef OPENGL_UTIL_H
#define OPENGL_UTIL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif

GLuint loadTexture(const char * filename,bool useMipMap = true);

void drawAxis3D(float scale = 1);

#endif //OPENGL_UTIL_H
