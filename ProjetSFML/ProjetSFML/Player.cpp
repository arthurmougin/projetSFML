#pragma once
#include "Player.h"
#include "Scene.h"

Player::Player() :MobileEntity()
{
	bringSomething = false;
	bringElement = NULL;
	bringColor = GameColor::NOCOLOR;
}

Player::Player(Vector2f pos, Texture tex, IntRect rect) :MobileEntity( 2, pos, tex, rect)
{
	bringSomething = false;
	bringElement = NULL;
	bringColor = GameColor::NOCOLOR;
}

void Player::update()
{
	cout << "player update" << endl;

}

void Player::moveTo(Direction d)
{
	MobileEntity::moveTo(d);
	IntRect tr = this->sprite.getTextureRect();
	if (d == Direction::DROITE) {
		tr.top = this->textureRect.top;
	}
	else if (d == Direction::GAUCHE) {
		tr.top = this->textureRect.top + 32;
	}
	this->sprite.setTextureRect(tr);
}
