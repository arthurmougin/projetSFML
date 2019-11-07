#include "Player.h"
#include "Scene.h"

Player::Player() :MobileEntity()
{
	bringSomething = false;
	bringElement = NULL;
	bringColor = GameColor::NOCOLOR;
}

void Player::update()
{
	cout << "player update" << endl;

}
