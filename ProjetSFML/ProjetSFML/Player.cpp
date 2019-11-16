#pragma once
#include "Player.h"
#include "Scene.h"

Player::Player() :MobileEntity()
{
	bringSomething = false;
	bringElement = NULL;
	bringColor = GameColor::NOCOLOR;
}

Player::Player(Vector2f pos, Texture tex, IntRect rect) :MobileEntity(pos, tex, rect)
{
	bringSomething = false;
	bringElement = NULL;
	bringColor = GameColor::NOCOLOR;
}

void Player::update()
{
	cout << "player update" << endl;

}
