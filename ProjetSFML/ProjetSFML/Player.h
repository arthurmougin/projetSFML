#pragma once
#include "MobileEntity.h"
class Scene;

class Player:public MobileEntity
{
protected:
	bool bringSomething;
	GameObject* bringElement;
	GameColor bringColor = NOCOLOR;
	FloatRect interactionBox = FloatRect(0, 0, 160, 160);

public:
	Player();
	Player(Vector2f, Texture, IntRect);
	void update(Scene *);
	FloatRect getInteractionBox();

	void moveTo(Direction);
	bool getBringSomething();
	void setBringSomething(bool);
	GameObject* getBringElement();
	void setBringElement(GameObject*);
	GameColor getBringColor();
	void setBringColor(GameColor);
	void placeBringElement();
	bool goingLeft();
};

