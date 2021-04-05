#include <iostream>

#include "GameScene.h"
#include "Input.h"
#include "DebugComponent.h"

GameScene::GameScene(const char* id):
	Scene(id)
{ }

GameScene::~GameScene() {}


GameObject* testGameObject;

void GameScene::beginScene(Scene* from)
{
	std::cout << "Loaded scene..." << std::endl;
	testGameObject = createGameObject();
	testGameObject->addComponent<DebugComponent>();

}

void GameScene::endScene(Scene* to)
{
	std::cout << "Ended scene" << std::endl;
}

void GameScene::onUpdate(float& dt)
{
	int fps = 1 / dt;

	if (Input::getKeyDown(KeyCode::A))
	{
		std::cout << "Pressed A!" << std::endl;
	}

	if (Input::getKeyUp(KeyCode::A))
	{
		std::cout << "Released A!" << std::endl;
	}

	if (Input::getKey(KeyCode::A))
	{
		std::cout << "Holding A..." << std::endl;
	}


}