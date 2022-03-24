#include "Player.hpp"
#include "InputComponent.hpp"
#include "sprite_component.hpp"
#include "game.hpp"
#include "circle_component.hpp"
#include "Obstacle.hpp"

Player::Player(Game* game)
	:Actor(game)
{
	//create sprite
	SpriteComponent* sc = new SpriteComponent(this, 100);
	sc->SetTexture(game->GetTexture("assets/circle.png"));

	//handle input
	InputComponent* ic = new InputComponent(this);
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->SetMaxForwardSpeed(300.0f);
	cc->SetRadius(16.0f);
}

void Player::UpdateActor(float deltaTime)
{
	
}

void Player::ActorInput(const uint8_t* keyState)
{
	Vec2 vel = { 0.0f, 0.0f };
	Vec2 pos = this->GetPosition();
	if (keyState[SDL_SCANCODE_SPACE])
	{
		this->SetPosition(Vec2(0.0f, 100.0f));
	}
	if (keyState[SDL_SCANCODE_A])
	{
		vel = { -3.0f, 0.0f };
	}
	if (keyState[SDL_SCANCODE_D])
	{
		vel = { 3.0f, 0.0f };
	}
	pos += vel;
	this->SetPosition(pos);
}