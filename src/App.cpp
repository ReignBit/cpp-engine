#include <fstream>
#include <iostream>

#include "App.h"
#include "Utils.h"
#include "Scene.h"
#include "Input.h"
#include "Renderer.h"

App::App() : m_renderer(m_window)
{

}

App::~App()
{
	delete m_window;
}


void App::loadConfig(const char* configPath)
{
	// Defaults
	//m_config["width"] = "852";
	//m_config["height"] = "480";
	//m_config["refreshrate"] = "60";
	//m_config["vsync"] = "0";

	std::ifstream fs(configPath);
	if (fs.is_open())
	{
		std::string line;
		while (std::getline(fs, line))
		{
			//key=option
			int index = line.find('=');

			std::cout << line << std::endl;

			std::string key = line.substr(0, index);
			std::string option = line.substr(index + 1, sizeof(line) - index);

			m_config[key] = option;
			std::cout << m_config[line.substr(0, index - 1)] << std::endl;
		}
		fs.close();
	}
}

void App::initWindow(std::string title)
{
	std::cout << m_config["width"] << "," << m_config["height"] << std::endl;
	
	sf::VideoMode vm(std::stoi(m_config["width"]), std::stoi(m_config["height"]));
	m_window = new sf::RenderWindow(vm, title);

	m_window->setKeyRepeatEnabled(false);	// Disable Key Repetition from holding down.
	m_window->setVerticalSyncEnabled(util::stob(m_config["vsync"]));
	m_window->setFramerateLimit(stoi(m_config["refreshrate"]));


	// Create our renderer
	m_renderer = Engine::Renderer(m_window);
}


/// <summary>
/// Adds a scene to the scene stack.
/// </summary>
/// <param name="scene">Ptr to the scene to push.</param>
void App::pushScene(Scene* scene)
{
	m_scenes.push(scene);
	std::cout << "Pushed scene: " << scene->id << " to the scene stack" << std::endl;
}


/// <summary>
/// Removes the active scene from the scene stack.
/// </summary>
void App::popScene()
{
	// Call for the deletion of all GameObjects and Components from the scene.
	m_scenes.top()->endScene();

	// Remove the scene from the stack, ready for the next one.
	m_scenes.pop();
}

void App::end()
{
	// Remove all scenes from the stack.
	for (size_t i = 0; i < m_scenes.size(); i++)
	{
		popScene();
	}

	// Close the window.
	m_window->close();
}

void App::run()
{
	sf::Clock clock;

	m_scenes.top()->beginScene();

	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				end();
				return;
			case sf::Event::KeyPressed:
				Input::processKeyPress(event);
				break;
			case sf::Event::KeyReleased:
				Input::processKeyRelease(event);
				break;
			}
		}

		update(clock.restart().asSeconds());
		Input::resetKeys(); // Resets keyPressed and keyReleased, so we can check for frame presses.
		render();

		if (m_scenes.top()->isReadyToEnd())
		{
			m_scenes.top()->endScene();
			popScene();

			if(!m_scenes.empty())
				m_scenes.top()->beginScene();
		}
	}
}

void App::update(float dt)
{
	//std::cout << dt << std::endl;
	if (!m_scenes.empty())
		m_scenes.top()->update(dt);
}

void App::render()
{
	m_window->clear();
	if (!m_scenes.empty())
		m_scenes.top()->render(*m_window);
	m_window->display();
}