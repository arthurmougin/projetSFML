#pragma once
#include "MobileEntity.h"
#include "FocusableElement.h"

enum movingState {
	IDLE,MOVING_LEFT,MOVING_RIGHT,JUMPINJG,FALLING
};

class MobileGameplayElement:public MobileEntity, public FocusableElement
{
protected:
	enum movingState MovingState;
	bool HateWalls;
	bool heavy;

public:
	MobileGameplayElement();
	MobileGameplayElement(bool, bool);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, Vector2f, Texture, IntRect);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, int, Vector2f, Texture, IntRect);

	enum movingState getMovingState();
	void setMovingState(enum movingState);
	bool getHateWalls();
	void setHateWalls(bool);
	bool getHeavy();
	void setHeavy(bool);
};

