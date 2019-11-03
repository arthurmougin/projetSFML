#pragma once
#include "GameEntity.h"

class FocusableElement:public GameEntity
{
protected:
	bool focused;
	bool locked;

public:
	FocusableElement();
	FocusableElement(bool, bool, bool);

	bool getFocused();
	void setFocused(bool);
	bool getLocked();
	void setLocked(bool);
};

