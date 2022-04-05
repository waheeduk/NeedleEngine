#include "MoveComponent.hpp"


MoveComponent::MoveComponent(class Actor* owner, int UpdateOrder )
	:Component(owner, UpdateOrder),
	mAngularSpeed(0.0f),
	mForwardSpeed(0.0f),
	mRotationalMovement(false),
	mMass(0.5f)
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

	if (!Math::Zero(mSumForces))
	{
		if (mRotationalMovement == true)
		{
			Vec2 pos = mOwner->GetPosition();
			pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
			mOwner->SetPosition(pos);
		}
		else
		{
			Vec2 acceleration = mSumForces / mMass;
			mSumForces = Vec2(0.0f, 0.0f);
			mVelocity += acceleration * deltaTime;
			Vec2 pos = mOwner->GetPosition();
			pos += mVelocity * deltaTime;
			std::cout << mVelocity << std::endl;
			mOwner->SetPosition(pos);
		}
	}
}

