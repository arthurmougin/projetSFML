#pragma once
#include "MobileEntity.h"
#include "FocusableElement.h"

enum MovingState {
	IDLE,MOVING_LEFT,MOVING_RIGHT,JUMPING,FALLING
};

class MobileGameplayElement:public MobileEntity, public FocusableElement
{
protected:
	enum MovingState movingState;
	bool HateWalls;
	bool heavy;

public:
	MobileGameplayElement();
	MobileGameplayElement(bool, bool);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, Vector2f, Texture, IntRect);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, int, Vector2f, Texture, IntRect);

	enum MovingState getMovingState();
	void setMovingState(enum MovingState);
	bool getHateWalls();
	void setHateWalls(bool);
	bool getHeavy();
	void setHeavy(bool);
};

