#include <iostream>

#include "Scene.h"
#include "GameObject.h"
#include "Transform.h"

Scene::Scene()
{

}

Scene::Scene(const char* id)
{
	this->id = id;
}

Scene::~Scene()
{
	for (GameObject* object : m_gameObjects)
	{
		delete object;
	}
}

/// <summary>
/// Called when the scene is loaded.
/// </summary>
/// <param name="from">The scene we switched from.</param>
void Scene::beginScene(Scene* from)
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->start();
	}
}

/// <summary>
/// Called when the scene ends.
/// </summary>
/// <param name="to">The scene we are switching to.</param>
void Scene::endScene(Scene* to)
{
	for (auto p : m_gameObjects)
	{
		delete p;
	}
	delete& m_gameObjects;
}

GameObject* Scene::createGameObject()
{
	GameObject* object = new GameObject();
	object->addComponent<Transform>();
	m_gameObjects.push_back(object);
	std::cout << "Created gameObject" << std::endl;
	return object;
}

bool Scene::isReadyToEnd()
{
	return m_bEndScene;
}

void Scene::SetEndSceneFlag()
{
	m_bEndScene = true;
}

/// <summary>
/// Called every frame.
/// </summary>
/// <param name="dt">time since the last frame.</param>
void Scene::update(float& dt)
{
	onUpdate(dt);
	for (GameObject* object : m_gameObjects)
	{
		if (object->enabled)
		{
			object->update(dt);

			if (object->scene == nullptr)
				object->scene = this;
		}
	}
}

void Scene::render(sf::RenderTarget& target)
{
	target.clear();
	for (GameObject* object : m_gameObjects)
	{
		if (object->enabled)
			object->render(target);
	}
}

void Scene::destroyGameObjects()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		delete& m_gameObjects[i];
	}
}