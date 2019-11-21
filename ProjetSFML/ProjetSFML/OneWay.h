#pragma once
#include "GameEntity.h"
class OneWay:public GameEntity
{
protected:
	enum Direction blockDirection;

public:
	OneWay();
	OneWay(Direction);
	OneWay(Direction,Vector2f, Texture, IntRect);

	Direction getBlockDirection();
	void setBlockDirection(Direction);
};

