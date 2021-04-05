#pragma once
#include <string>
#include <stack>

#include "SFML/Graphics.hpp"
#include "Renderer.h"
#include "MessageBus.h"


class Scene;
class App {

public:
	App();
	~App();

	void loadConfig(const char* configPath);
	void initWindow(std::string title);
	void run();
	void end();

	void pushScene(Scene* scene);
	void popScene();

	void update(float dt);
	void render();


private:
	std::map<std::string, std::string> m_config;
	sf::RenderWindow* m_window;
	Engine::Renderer m_renderer;

	std::stack<Scene*> m_scenes;
};

