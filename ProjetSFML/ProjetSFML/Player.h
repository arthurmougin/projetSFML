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
	Player(Vector2f, Texture, IntRect);
	void update();

	void moveTo(Direction);

};

