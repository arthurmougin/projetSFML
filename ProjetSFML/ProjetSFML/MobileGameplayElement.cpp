#include "MobileGameplayElement.h"

MobileGameplayElement::MobileGameplayElement():MobileEntity(),FocusableElement()
{
	MovingState = IDLE;
	HateWalls = true;
	heavy = false;
}

MobileGameplayElement::MobileGameplayElement(bool hw, bool hv) :MobileEntity(), FocusableElement()
{
	MovingState = IDLE;
	HateWalls = hw;
	heavy = hv;
}

MobileGameplayElement::MobileGameplayElement(bool hateW, bool heavii, bool fly, double Speed, bool TraverseBlock, bool TraverseMur, bool MarcheSurBlock, bool traversable, Vector2f position, Texture texture, IntRect textrect):MobileEntity(fly, Speed, TraverseBlock, TraverseMur, MarcheSurBlock, position, texture, textrect),FocusableElement(traversable)
{
	MovingState = IDLE;
	HateWalls = hateW;
	heavy = heavii;
}

enum movingState MobileGameplayElement::getMovingState()
{
	return MovingState;
}

void MobileGameplayElement::setMovingState(enum movingState m)
{
	MovingState = m;
}

bool MobileGameplayElement::getHateWalls()
{
	return HateWalls;
}

void MobileGameplayElement::setHateWalls(bool h)
{
	HateWalls = h;
}

bool MobileGameplayElement::getHeavy()
{
	return heavy;
}

void MobileGameplayElement::setHeavy(bool h)
{
	heavy = h;
}
