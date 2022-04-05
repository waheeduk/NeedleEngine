#pragma once
#include <random>
#include "Vec2.hpp"

Vec2 RandomVec2() //produces a random vec2 with x and y between -1 and 1
{
	Vec2 Output;
	std::random_device rd;
	std::uniform_int_distribution<> distr(-1, 1);
	std::mt19937 gen(rd());
	float OutputX = distr(gen);
	float OutputY = distr(gen);
	Output.x = OutputX;
	Output.y = OutputY;
	std::cout << Output << std::endl;
	if ((Output.x == 0.0f) && (Output.y == 0.0f))
	{
		return RandomVec2();
	}
	else
	{
		return Output;
	}
}

Vec2 RandomInvertedVec2(Vec2 a, int invert) //takes in a previous vector2 and randomises one component whilst inversing the other
{
	Vec2 Output;
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(-1, 1);
	int OutputX, OutputY;
	if (invert == 0)
	{
		OutputX = a.x * -1;
		OutputY = distribution(generator);
	}
	if (invert == 1)
	{
		OutputY = a.y * -1;
		OutputX = distribution(generator);
	}
	return Output;
}