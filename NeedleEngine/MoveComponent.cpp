#include "MoveComponent.hpp"


MoveComponent::MoveComponent(class Actor* owner, int UpdateOrder )
	:Component(owner, UpdateOrder),
	mAngularSpeed(0.0f),
	mForwardSpeed(0.0f)
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
		Vec2 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}
}

