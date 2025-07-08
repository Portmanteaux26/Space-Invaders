#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


#include <map>
#include <string>

#include <glad/glad.h>

#include "Shader.h"
#include "Texture.h"


class ResourceManager
{
public:
	// storage
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture2D> Textures;
	// loads shader program
	static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
	// gets stored shader
	static Shader& GetShader(std::string name);
	// loads texture
	static Texture2D LoadTexture(const char* file, bool alpha, std::string name);
	// gets stored texture
	static Texture2D& GetTexture(std::string name);
	// cleans up
	static void Clear();
private:
	// private constructor
	ResourceManager() { }
	// loads shader from file
	static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
	//loads texture from file
	static Texture2D loadTextureFromFile(const char* file, bool alpha);
};


#endif