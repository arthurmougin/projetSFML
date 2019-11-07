#pragma once
#include "MobileEntity.h"

class Player:public MobileEntity
{
protected:
	bool bringSomething;
	GameObject* bringElement;
	enum GameColor bringColor;

public:
	Player();
	void update();


};

