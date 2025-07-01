#ifndef TEXTURE_H
#define TEXTURE_H


#include <glad/glad.h>


class Texture2D
{
public:
    unsigned int ID;
    // loaded image dimensions (in pixels)
    unsigned int Width, Height;
    // format
    unsigned int Internal_Format; // texture object
    unsigned int Image_Format; // loaded image
    // configuration
    unsigned int Wrap_S; // wrapping mode on S axis
    unsigned int Wrap_T; // wrapping mode on T axis
    unsigned int Filter_Min; // filtering mode if texture pixels < screen pixels
    unsigned int Filter_Max; // filtering mode if texture pixels > screen pixels
    // constructor
    Texture2D();
    // generates texture
    void Generate(unsigned int width, unsigned int height, unsigned char* data);
    // binds texture
    void Bind() const;
};


#endif