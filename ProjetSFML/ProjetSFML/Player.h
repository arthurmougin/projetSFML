#pragma once
#include "MobileEntity.h"
class Player:public MobileEntity
{
protected:
	bool bringSomething;
	ElementContainer& bringElement;
	GameColor bringColor;

public:
	Player();
	void update();
};

