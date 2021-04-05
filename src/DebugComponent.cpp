#include <iostream>

#include "SFML/Graphics.hpp"

#include "DebugComponent.h"
#include "Scene.h"
#include "Transform.h"
#include "GameObject.h"
#include "Input.h"

sf::Text text;
sf::Font font;

unsigned int fps;

DebugComponent::DebugComponent()
{

}

DebugComponent::~DebugComponent()
{
	std::cout << "Deleted DebugComponent" << std::endl;
}

void DebugComponent::start()
{
	font.loadFromFile("Resources/Fonts/DPCOMIC.TTF");
	text.setFont(font);

	std::cout << "DebugComponent instance started" << std::endl;
}

void DebugComponent::update(float& dt)
{
	fps = static_cast<unsigned int>(1 / dt);
	//std::cout << fps << std::endl;
	text.setString("FPS: " + std::to_string(fps));

	if (Input::getKey(KeyCode::D))
	{
		Vector2* transform = &gameObject->getComponent<Transform>()->position;
		transform->x += 100.0f * dt;
	}

	if (Input::getKey(KeyCode::A))
	{
		Vector2* transform = &gameObject->getComponent<Transform>()->position;
		transform->x -= 100.0f * dt;
	}

	if (Input::getKey(KeyCode::W))
	{
		Vector2* transform = &gameObject->getComponent<Transform>()->position;
		transform->y -= 100.0f * dt;
	}

	if (Input::getKey(KeyCode::S))
	{
		Vector2* transform = &gameObject->getComponent<Transform>()->position;
		transform->y += 100.0f * dt;
	}


	text.setPosition(gameObject->getComponent<Transform>()->position.x, gameObject->getComponent<Transform>()->position.y);
}

void DebugComponent::render(sf::RenderTarget& target)
{
	target.draw(text);
}