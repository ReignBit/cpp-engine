#pragma once
#include <string>

#include "SFML/Graphics.hpp"

class GameObject;
class Scene {
public:
	Scene();
	Scene(const char* id);
	~Scene();

	std::string id = "Unnamed Scene";

	GameObject* createGameObject();

	virtual void beginScene(Scene* from = nullptr) = 0;
	virtual void endScene(Scene* to = nullptr) = 0;
	virtual void onUpdate(float& dt) = 0;
	
	void update(float& dt);

	void destroyGameObjects();
	void render(sf::RenderTarget& target);

	bool isReadyToEnd();
	void SetEndSceneFlag();

protected:
	bool m_bEndScene = false;
	std::vector<GameObject*> m_gameObjects;
};