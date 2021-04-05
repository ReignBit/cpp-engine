#pragma once
#include <iostream>

struct Vector2 {
	Vector2(float x, float y);
	Vector2();
	~Vector2();
	
	float x, y;

	static Vector2 zero();
	static Vector2 down();

	friend std::ostream& operator<<(std::ostream& os, Vector2 dt);

};