#include "Player.h"
#include "Scene.h"

Player::Player() :MobileEntity()
{
	bringSomething = false;
	bringColor = NOCOLOR;
	ElementContainer E;
	E.type = VIDE;
	bringElement = E;
}

void Player::update()
{
	cout << "player update" << endl;

}
