#include "Renderer.h"

Renderer::Renderer(MyShader shader)
{
	this->active = true;
	this->comtype = ComponentType::RENDERER;
	this->shader = shader;
	enableTexture = false;
	this->InitRenderer();
}

Renderer::Renderer(MyShader shader,Texture2D texture)
{
	this->active = true;
	this->comtype = ComponentType::RENDERER;
	this->shader = shader;
	this->texture = texture;
	enableTexture = true;
	this->InitRenderer();
}

void Renderer::InitRenderer()
{
	GLfloat vertices[] = {
		// Î»ÖÃ     // ÎÆÀí
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};
	GLuint VBO;
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindVertexArray(this->VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Renderer::draw(glm::vec2 position, glm::vec2 size, float rotate,glm::vec3 color)
{
	if (active == false) return;
	shader.use();
	glm::mat4 model(1.0);
	model = glm::translate(model, glm::vec3(position,0));

	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	model = glm::scale(model, glm::vec3(size, 1.0f));

	shader.setMat4("model", model);
	shader.setBool("enableTexture", enableTexture);
	shader.setVec3("spriteColor", color);
	if (enableTexture) {
		texture.Bind();
		glActiveTexture(GL_TEXTURE0);
	}
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES,0, 6);
	glBindVertexArray(0);
}
