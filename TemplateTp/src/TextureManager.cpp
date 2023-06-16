//
// Created by isi on 1/19/2023.
//

#include "TextureManager.h"

void TextureManager::init(){
    GLuint skyboxWater  = loadTexture("assets/sprites/skybox.png",false);
    textures.push_back(std::make_pair("skybox1", skyboxWater));

    GLuint grassTexture  = loadTexture("assets/sprites/grass.jpg", false);
    textures.push_back(std::make_pair("grass", grassTexture));

    GLuint darkSky  = loadTexture("assets/sprites/skybox.jpg",false);
    textures.push_back(std::make_pair("skybox2", darkSky));

    GLuint grassMinecraftTexture  = loadTexture("assets/sprites/grass_minecraft.png", false);
    textures.push_back(std::make_pair("grass_minecraft", grassMinecraftTexture));
}

GLuint TextureManager::getTexture(std::string textureName) {
    GLuint idTexture = -1;
    for(auto texture : textures){
        if(texture.first == textureName){
            idTexture =  texture.second;
        }
    }
    return  idTexture;
}


TextureManager::~TextureManager() {
    textures.clear();

    for(int i = 0; i < 4; i++){
        glDeleteTextures(1, &textures[i].second);
    }
}
