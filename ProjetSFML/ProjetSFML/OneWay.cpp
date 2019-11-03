#include "OneWay.h"

OneWay::OneWay():GameEntity()
{
	blockDirection = HAUT;
}

OneWay::OneWay(Direction d):GameEntity()
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
