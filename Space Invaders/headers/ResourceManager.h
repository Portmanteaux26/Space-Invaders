#pragma once

#include <map>
#include <string>

#include <glad/glad.h>

#include "Texture.h"
#include "Shader.h"


class ResourceManager
{
public:
    // resource storage
    static std::map<std::string, Shader>    Shaders;
    static std::map<std::string, Texture2D> Textures;
    // loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code
    static Shader& LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, const std::string name);
    // retrieves a stored sader
    static Shader& GetShader(const std::string name);
    // loads (and generates) a texture from file
    static Texture2D& LoadTexture(const char* file, const bool alpha, const std::string name);
    // retrieves a stored texture
    static Texture2D& GetTexture(const std::string name);
    // properly de-allocates all loaded resources
    static void Clear();
private:
    // private constructor
    ResourceManager()
    {

    }
    // loads and generates a shader from file
    static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
    // loads a single texture from file
    static Texture2D loadTextureFromFile(const char* file, const bool alpha);
};