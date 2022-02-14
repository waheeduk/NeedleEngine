#pragma once

#include "Components.hpp"

class Entity
{
public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CName> cName;
	Entity() {}
};