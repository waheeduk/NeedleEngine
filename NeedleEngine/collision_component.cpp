#include "collision_component.hpp"

CollisionComponent::CollisionComponent(class Actor* owner, int UpdateOrder)
	:Component(owner)
{

}

bool CollisionComponent::CircleCollision(CircleComponent& a, CircleComponent& b)
{
	// returns true if collision //
	//gets distance squared between circle components
	Vec2 dist = a.GetCenter();
	float distSq = dist.distanceSq(b.GetCenter());
	//get sum of radii squared 
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}

bool CollisionComponent::RectCollision(SDL_Rect& a, SDL_Rect& b)
{
	//simple AABB collision system
	if (!
		a.x > b.x + b.h &&
		a.x + a.w < b.x &&
		a.y + a.h < b.y &&
		a.y > b.y + b.h
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionComponent::CircleRectCollision(const CircleComponent& a, const RectComponent& b)
{
	//find closest point from circle to square
	Vec2 closest;
	float x_right = b.GetPos().x + b.GetDimensions().x;
	float y_right = b.GetPos().y + b.GetDimensions().y;
	closest.x = std::max((float)b.GetPos().x, std::min(x_right, a.GetCenter().x));
	closest.y = std::max((float)b.GetPos().y, std::min(y_right, a.GetCenter().y));
	//see if magnitude of circle to closest point is smaller than radius meaning a collision is detected
	float distSq = closest.distanceSq(a.GetCenter());
	return distSq < a.GetRadiusSq();
}

float CollisionComponent::ResolveCircleRectCollision(const CircleComponent& a, const RectComponent& b)
{
	Vec2 closest;
	float x_right = b.GetPos().x + b.GetDimensions().x;
	float y_right = b.GetPos().y + b.GetDimensions().y;
	closest.x = std::max((float)b.GetPos().x, std::min(x_right, a.GetCenter().x));
	closest.y = std::max((float)b.GetPos().y, std::min(y_right, a.GetCenter().y));
	//see if magnitude of circle to closest point is smaller than radius meaning a collision is detected
	float dist = closest.distance(a.GetCenter());
	if (dist < a.GetRadius())
	{
		float overlap = a.GetRadius() - dist;
		return overlap;
	}
	else
	{
		return 0.0f;
	}
}