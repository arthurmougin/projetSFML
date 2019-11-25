#include "FocusableElement.h"

FocusableElement::FocusableElement():GameEntity(true)
{
}

FocusableElement::FocusableElement(bool t)
{
	traversable = t;
}

FocusableElement::FocusableElement(bool f, bool l, bool t):GameEntity()
{
	focused = f;
	locked = l;
	traversable = t;
}

FocusableElement::FocusableElement( bool trav, Vector2f pos, Texture tex, IntRect rect) : GameEntity(trav, pos, tex, rect)
{
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
