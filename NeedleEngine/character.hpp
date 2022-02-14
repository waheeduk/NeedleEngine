#pragma once
#include "actor.hpp"
#include "animsprite_component.hpp"

class Character : public Actor
{
public:
	Character(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state);
	AnimSpriteComponent* anim = new AnimSpriteComponent(this);
};