#pragma once
#include "actor.hpp"
#include "collision_component.hpp"

class Player : public Actor
{
public:
	Player(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;
	//circle component
	CircleComponent* cc = new CircleComponent(this);
	//collision component
	CollisionComponent* collider = new CollisionComponent(this);
};