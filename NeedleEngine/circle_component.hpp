#pragma once
#include "components.hpp"

class CircleComponent : public Component
{
public:
	CircleComponent(class Actor* owner);
	//basic setters getters
	void SetRadius(float r) { mRadius = r; }
	float GetRadius() const { return mRadius; }
	float GetRadiusSq() const { return (mRadius * mRadius); }
	const Vec2& GetCenter() const;
private:
	float mRadius;
};