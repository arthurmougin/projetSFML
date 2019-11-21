#include "OneWay.h"

OneWay::OneWay():GameEntity()
{
	blockDirection = Direction::HAUT;
}

OneWay::OneWay(Direction d):GameEntity()
{
	blockDirection = d;
}

OneWay::OneWay(Direction d, Vector2f pos, Texture tex, IntRect rect) : GameEntity(false,pos, tex, rect)
{
	blockDirection = d;
}

Direction OneWay::getBlockDirection()
{
	return blockDirection;
}

void OneWay::setBlockDirection(Direction d)
{
	blockDirection = d;
}