#pragma once

#include "SFML/Graphics.hpp"
class GameObject;
class Component {
public:
	Component():enabled(true), gameObject(nullptr) {};
	Component(GameObject* parent);
	virtual ~Component() {};

	GameObject* gameObject;

	bool enabled;

	/// <summary>
	/// Called when a scene is created.
	/// </summary>
	/// <param name=""></param>
	virtual void start() = 0;
	virtual void update(float& dt) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
	void SetActive(bool state);
};

