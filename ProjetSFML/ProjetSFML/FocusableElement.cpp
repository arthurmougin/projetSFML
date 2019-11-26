#include "FocusableElement.h"

FocusableElement::FocusableElement():GameEntity(true)
{
	focused = locked = false;
}

FocusableElement::FocusableElement(bool t): GameEntity(t)
{
	focused = locked = false;
}

FocusableElement::FocusableElement(bool f, bool l, bool t):GameEntity(t)
{
	focused = f;
	locked = l;
}

FocusableElement::FocusableElement( bool trav, Vector2f pos, Texture tex, IntRect rect) : GameEntity(trav, pos, tex, rect)
{
}

FocusableElement::FocusableElement(bool trav, int interframe, Vector2f pos, Texture tex, IntRect rect) : GameEntity(trav, interframe, pos, tex, rect)
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
