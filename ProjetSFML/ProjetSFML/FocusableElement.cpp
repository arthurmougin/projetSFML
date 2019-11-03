#include "FocusableElement.h"

FocusableElement::FocusableElement():GameEntity(true)
{
	focused = locked = false;
}

FocusableElement::FocusableElement(bool f, bool l, bool t):GameEntity()
{
	focused = f;
	locked = l;
	traversable = t;
}

bool FocusableElement::getFocused()
{
	return focused;
}

void FocusableElement::setFocused(bool f)
{
	focused = f;
}

bool FocusableElement::getLocked()
{
	return locked;
}

void FocusableElement::setLocked(bool l)
{
	locked = l;
}
