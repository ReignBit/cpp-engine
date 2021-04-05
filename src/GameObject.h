#pragma once
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"

struct Vector2;
class Component;
class Scene;
class GameObject {
public:
	GameObject();
	GameObject(Vector2& position);
	GameObject(Vector2& position, Vector2& rotation);
	GameObject(Vector2& position, Vector2& rotation, Vector2& scale);
	~GameObject();

	void start();

	void update(float& dt);
	void render(sf::RenderTarget& target);
	
	template<class T> T* getComponent();
	template<class T> T* addComponent();
	bool removeComponent(Component* comp);

	Scene* scene;

	bool enabled;




protected:
	std::vector<Component*> m_components;
	
};

template<class T>
T* GameObject::getComponent()
{
	for (size_t i = 0; i < m_components.size(); i++)
	{
		if (dynamic_cast<T*>(m_components[i]) != NULL)
		{
			return dynamic_cast<T*>(m_components[i]);
		}
	}
	return NULL;
}

template<class T>
T* GameObject::addComponent()
{
	T* new_component = new T;

	dynamic_cast<Component*>(new_component)->gameObject = this;

	m_components.push_back(new_component);
	std::cout << "Created component" << std::endl;
	std::cout << "size of m_components " << m_components.size() << std::endl;
	new_component->start();
	return new_component;
}
