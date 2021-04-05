#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include <cassert>


using namespace Engine;

void Renderer::setRenderTarget(sf::RenderTarget* rt)
{
	m_currentRenderTarget = rt;
}

void Renderer::render(sf::Drawable* drawable)
{
	m_currentRenderTarget->draw(*drawable);
}
