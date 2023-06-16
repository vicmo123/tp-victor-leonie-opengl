//
// Created by isi on 1/19/2023.
//

#ifndef QUADRIC_ARBRES_TEXTUREMANAGER_H
#define QUADRIC_ARBRES_TEXTUREMANAGER_H

#include "gameDefine.h"
#include "math.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include <vector>
#include <map>
#include "opengl_util.h"
#include "Singleton.h"

class TextureManager : public Singleton<TextureManager> {
    std::vector<std::pair<std::string, GLuint>> textures;
    int numberOfTextures;
public:
    void init();
    GLuint getTexture(std::string textureName);
    virtual ~TextureManager();
};


#endif //QUADRIC_ARBRES_TEXTUREMANAGER_H
