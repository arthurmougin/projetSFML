#pragma once
#include "GameEntity.h"
#include "Scene.h"
class OneWay:public GameEntity
{
protected:
	enum Direction blockDirection;

public:
	OneWay();
	OneWay(Direction);

	Direction getBlockDirection();
	void setBlockDirection(Direction);
};

