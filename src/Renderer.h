#pragma once

#include "MessageBus.h"

namespace Engine
{
	class Renderer {
	public:
		Renderer(sf::RenderTarget* rt) : m_currentRenderTarget(rt) { }

		~Renderer() {}

		void render(sf::Drawable* drawable);
		void setRenderTarget(sf::RenderTarget* rt);

	private:
		sf::RenderTarget* m_currentRenderTarget;
	};
}


