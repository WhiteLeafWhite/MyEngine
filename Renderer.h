#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Component.h"
#include "MyShader.h"
#include "Texture2D.h"
class Renderer :
    public Component
{
private:
    GLuint VAO;
    Texture2D texture;
    MyShader shader;
    bool enableTexture;
public:
    Renderer() = default;
    Renderer(MyShader shader);
    Renderer(MyShader shader, Texture2D texture);
    void InitRenderer();
    void draw(glm::vec2 position,glm::vec2 size,float rotate, glm::vec3 color);
};

