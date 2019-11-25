#pragma once
#include "GameEntity.h"

class FocusableElement:public GameEntity
{
protected:
	bool focused = false;
	bool locked = false;

public:
	FocusableElement();
	FocusableElement(bool);
	FocusableElement(bool, bool, bool);
	FocusableElement(bool, Vector2f, Texture, IntRect);

	bool getFocused();
	void setFocused(bool);
	bool getLocked();
	void setLocked(bool);
};

