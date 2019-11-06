#include "Player.h"
#include "Scene.h"

Player::Player() :MobileEntity()
{
	bringSomething = false;
	bringColor = NOCOLOR;
}

void Player::update()
{
	cout << "player update" << endl;

}
