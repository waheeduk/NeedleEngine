#pragma once
#include "components.hpp"
#include "Math.hpp"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int UpdateOrder = 10);
	void Update(float deltaTime) override;
	float GetForwardSpeed() { return mForwardSpeed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	float GetAngularSpeed() { return mAngularSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
private:
	//controls rotational speed
	float mAngularSpeed;
	//controls movement speed
	float mForwardSpeed;
};