/*
	Transform.cpp

	Component attached to GameObjects
	Responsible for managing a GameObject's position, rotation, and scale.
	GameObjects should not really be created without this component.

	However, there may be some cases where we want "abstract" objects, so it is
	provided as a component instead.

*/

#include "Transform.h"

/// <summary>
/// Create Transform without parent. Set parent before using!
/// </summary>
Transform::Transform()
{

}

Transform::Transform(GameObject* parent)
	:Component(parent), position(0, 0), rotation(0, 0), scale(0,0)
{

}

Transform::~Transform()
{
}

void Transform::start()
{

}

void Transform::update(float& dt)
{
}

void Transform::render(sf::RenderTarget& target)
{

}