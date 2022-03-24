#include "actor.hpp"
#include "circle_component.hpp"
#include "rect_component.hpp"
#include <SDL.h>

class Obstacle : public Actor
{
public:
	Obstacle(class Game* game);
	RectComponent* r = new RectComponent(this, 32, 32);
};