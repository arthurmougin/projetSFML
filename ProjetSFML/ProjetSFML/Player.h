#pragma once
#include "MobileEntity.h"

class Player:public MobileEntity
{
protected:
	bool bringSomething;
	GameObject* bringElement;
	GameColor bringColor;

public:
	Player();
	void update();


};

