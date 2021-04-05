#include "Component.h"

Component::Component(GameObject* parent)
	: gameObject(parent), enabled(true)
{
}

void Component::SetActive(bool state)
{
	enabled = state;
}