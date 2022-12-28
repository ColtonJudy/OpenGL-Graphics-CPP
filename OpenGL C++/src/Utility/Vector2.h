#pragma once

struct Vector2 
{
	float x;
	float y;

	//this constructor exists for the declaration of static vector2s, as there is no default constructor
	Vector2() 
	{
		x = 0;
		y = 0;
	}

	Vector2(float x, float y) 
	{
		this->x = x;
		this->y = y;
	}
};