#include "Obstacle.hpp"
#include "sprite_component.hpp"
#include "game.hpp"

Obstacle::Obstacle(Game* game)
	:Actor(game)
{
	//create sprite
	SpriteComponent* sc = new SpriteComponent(this, 100);
	sc->SetTexture(game->GetTexture("assets/square.png"));
	
	SetPosition(Vec2(200.0f, 200.0f));
	GetGame()->AddObstacles(this);
}