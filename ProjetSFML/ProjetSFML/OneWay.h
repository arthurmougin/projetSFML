#pragma once
#include "GameEntity.h"
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
