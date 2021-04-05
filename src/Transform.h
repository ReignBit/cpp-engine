#pragma once
#include "Component.h"
#include "Vector2.h"

class GameObject;
class Transform : public Component {
public:
	Vector2 position;
	Vector2 rotation; // Might need an alternate data structure, but hopefully we can just use this being xdegrees from up...
	Vector2 scale;

	Transform();
	Transform(GameObject* parent);
	~Transform();

	virtual void start();
	virtual void update(float& dt);
	virtual void render(sf::RenderTarget& target);
};