#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imconfig.h>
#include <imgui_internal.h>
#include <fstream>
#include <ft2build.h>
#include <map>
#include < iomanip >
#include<ctime>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "GameObject.h"
#include "Rigidbody.h"
#include "Globaldefine.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <mmsystem.h>
#include "Script.h"
#include "scripts.h"
#include "Texture2D.h"
#pragma comment(lib,"winmm.lib")
#include "ResourceManager.h"
#include "PrefabManager.h"
#include "GameObjectManager.h"
#include "MousePos.h"
using namespace std;
const int width = 800;
const int height = 800;
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

GameObject makehosino();
GameObject makemika();
GameObject makebigsnake();
GameObject makekokomi();
GLFWwindow* window;
vector<GameObject> wives;
int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, "woshinidie", NULL, NULL);
	if (window == NULL) {
		cout << "failed to create window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//����1����ѭ���Ĵ���
	int millisecondsPerIteration = 1000 / FREQUENCY;
	clock_t startTime, currentTime;
	int tt = 0;

	//bgm
	
	//mciSendString(L"open ./bgm/alice.mp3", NULL, NULL, NULL);
	//mciSendString(L"play ./bgm/alice.mp3", NULL, NULL, NULL);

	// ������ɫ��

	ResourceManager::LoadShader("vertex.vs", "fragment.fs",nullptr, "characterShader");
	ResourceManager::GetShader("characterShader");
	MyShader shader = ResourceManager::GetShader("characterShader");
	shader.use();
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(width),
		static_cast<GLfloat>(height), 0.0f, -1.0f, 1.0f);
	shader.setMat4("projection", projection);

	//��������
	ResourceManager::LoadTexture("skin/alice.jpg", false, "aliceTexture");
	ResourceManager::LoadTexture("skin/yuzi.jpg", false, "yuziTexture");
	ResourceManager::LoadTexture("skin/hosino.jpg", false, "hosinoTexture");
	ResourceManager::LoadTexture("skin/mika.jpg", false, "mikaTexture");
	ResourceManager::LoadTexture("skin/bigsnake.jpg", false, "bigsnakeTexture");
	ResourceManager::LoadTexture("skin/fish.jpeg", false, "kokomiTexture");
	//����Ԥ����
	//����Ԥ����ġ�����
	PrefabManager::LoadPrefab(makehosino, "hoshino");
	PrefabManager::LoadPrefab(makemika, "mika");
	PrefabManager::LoadPrefab(makebigsnake, "bigsnake");
	PrefabManager::LoadPrefab(makekokomi, "kokomi");
	//����һЩGameObject
	GameObjectManager::getinstance()->emplace_go(PrefabManager::MakePrefab("kokomi"));
	GameObjectManager::getinstance()->emplace_go(PrefabManager::MakePrefab("kokomi"));
	GameObjectManager::getinstance()->emplace_go(PrefabManager::MakePrefab("kokomi"));
	GameObjectManager::getinstance()->start_all();
	while (!glfwWindowShouldClose(window))
	{
		//��һ֡��ʼ��ʱ��
		startTime = clock();
		//Render
		glClearColor(0, 0.5, 0.5, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		processInput(window);
	
		//������
		MousePos::getinstance()->update(window);
		

		//�����ǻ��Ʋ�����GameObject�ĵط�
		GameObjectManager::getinstance()->draw_all();
		GameObjectManager::getinstance()->updateScript_all();

		//��������
		glfwSwapBuffers(window);
		glfwPollEvents();
		//��һ֡������ʱ��
		currentTime = clock();
		int elapsedTime = (int)(1000.0 * (currentTime - startTime) / CLOCKS_PER_SEC);
		// ���������ʱ�䲻��ÿ�ε��������ʱ�䣬�͵ȴ����µ�ʱ��
		if (elapsedTime < millisecondsPerIteration) {
			int sleepTime = millisecondsPerIteration - elapsedTime;
			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime)); // ���뼶������ߣ���Ҫ���� <unistd.h> ͷ�ļ�
		}
	};
	return 0;
}

GameObject makehosino()
{
	GameObject hosino;
	Renderer r(ResourceManager::GetShader("characterShader"), ResourceManager::GetTexture("hosinoTexture"));
	hosino.addRenderer(r);
	//HosinoScript s(window,"alice");
	HosinoScript s(window,"alice");
	hosino.addScript("HosinoScript");
	return hosino;
}

GameObject makemika() {
	GameObject mika;
	Renderer r(ResourceManager::GetShader("characterShader"), ResourceManager::GetTexture("mikaTexture"));
	mika.addRenderer(r);
	HosinoScript s(window, "mika");
	mika.addScript("HosinoScript");
	return mika;
}

GameObject makebigsnake()
{
	GameObject snake;
	Renderer r(ResourceManager::GetShader("characterShader"), ResourceManager::GetTexture("bigsnakeTexture"));
	snake.addRenderer(r);
	SnakeScript s(window, "mika");
	snake.addScript("SnakeScript");
	return snake;
}

GameObject makekokomi()
{
	GameObject kokomi;
	kokomi.name = "ɺ�����ĺ�";
	Renderer r(ResourceManager::GetShader("characterShader"), ResourceManager::GetTexture("kokomiTexture"));
	kokomi.addRenderer(r);
	KokomiScript s;
	kokomi.addScript("KokomiScript");
	Collider c;
	kokomi.addCollider(c);
	return kokomi;
}