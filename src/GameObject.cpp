#include <typeinfo>

#include "GameObject.h"
#include "Transform.h"
#include "Component.h"


GameObject::GameObject()
	:enabled(true)
{

}

GameObject::GameObject(Vector2& position)
	:enabled(true)
{
	Transform* transform = addComponent<Transform>();
	transform->position = position;
}

GameObject::GameObject(Vector2& position, Vector2& rotation)
	:enabled(true)
{
	Transform* transform = addComponent<Transform>();
	transform->position = position;
	transform->rotation = rotation;
}

GameObject::GameObject(Vector2& position, Vector2& rotation, Vector2& scale)
	:enabled(true)
{
	Transform* transform = addComponent<Transform>();
	transform->position = position;
	transform->rotation = rotation;
	transform->scale = scale;
}

GameObject::~GameObject()
{
	for (auto p : m_components)
	{
		delete p;
	}
	m_components.empty();
}

void GameObject::start()
{
	for (size_t i = 0; i < m_components.size(); i++)
	{
		m_components[i]->start();
	}
}

/// <summary>
/// Remove a component from the gameObject
/// </summary>
/// <param name="comp">Pointer of component to remove.</param>
bool GameObject::removeComponent(Component* comp)
{
	int index_to_remove = -1;

	for (size_t i = 0; i < m_components.size(); i++)
	{
		if (m_components[i] == comp)
		{
			// The same component?
			index_to_remove = i;
		}
	}

	if (index_to_remove == -1)
	{
		// Didn't find component to remove.
		return false;
	}

	Component* del = m_components[index_to_remove];
	m_components.erase(m_components.begin() + (index_to_remove - 1));
	delete del;

	return true;
}

void GameObject::update(float& dt)
{
	if (enabled)
	{
		// For each component, update
		for (size_t i = 0; i < m_components.size(); i++)
		{
			m_components[i]->update(dt);
		}
	}
}

void GameObject::render(sf::RenderTarget& target)
{
	for (Component* component : m_components)
	{
		if (component->enabled)
			component->render(target);
	}
}
