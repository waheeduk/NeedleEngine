#pragma once
#include "character.hpp"
#include "animsprite_component.hpp"
#include "game.hpp"

Character::Character(class Game* game)
	:Actor(game)
{
	std::vector<SDL_Texture*> animtex = {
		game->GetTexture("assets/Character01.png"),
		game->GetTexture("assets/Character02.png"),
		game->GetTexture("assets/Character03.png"),
		game->GetTexture("assets/Character04.png"),
		game->GetTexture("assets/Character05.png"),
		game->GetTexture("assets/Character06.png"),
		game->GetTexture("assets/Character07.png"),
		game->GetTexture("assets/Character08.png"),
		game->GetTexture("assets/Character09.png"),
		game->GetTexture("assets/Character10.png"),
		game->GetTexture("assets/Character11.png"),
		game->GetTexture("assets/Character12.png"),
		game->GetTexture("assets/Character13.png"),
		game->GetTexture("assets/Character14.png"),
		game->GetTexture("assets/Character15.png"),
		game->GetTexture("assets/Character16.png"),
		game->GetTexture("assets/Character17.png"),
		game->GetTexture("assets/Character18.png")
	};
	anim->SetAnimTextures(animtex);
	struct Animation walk = { 0, 6, 10, "walk", true };
	struct Animation jump = { 7, 10, 10, "jump", true };
	anim->AddAnimation(walk);
	anim->AddAnimation(jump);
	anim->SetCurrentAnimation("walk");
}

void Character::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
}

void Character::ProcessKeyboard(const uint8_t* state)
{
	if (state[SDL_SCANCODE_SPACE])
	{
		anim->SetCurrentAnimation("jump");
		std::cout << "space key detected by character class" << std::endl;
	}
}