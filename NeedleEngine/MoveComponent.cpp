#include "MoveComponent.hpp"


MoveComponent::MoveComponent(class Actor* owner, int UpdateOrder )
	:Component(owner, UpdateOrder),
	mAngularSpeed(0.0f),
	mForwardSpeed(0.0f),
	mRotationalMovement(false)
{

}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::Zero(mAngularSpeed))
	{
		float rotation = mOwner->GetRotation();
		rotation += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rotation);
	}

	if (!Math::Zero(mForwardSpeed))
	{
		if (mRotationalMovement == true)
		{
			Vec2 pos = mOwner->GetPosition();
			pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
			mOwner->SetPosition(pos);
		}
		else
		{
			Vec2 pos = mOwner->GetPosition();
			Vec2 vel = mOwner->GetForwardDir() * mForwardSpeed * deltaTime;
			pos += vel;
			mOwner->SetPosition(pos);
		}
	}
}

