#include "MobileGameplayElement.h"

MobileGameplayElement::MobileGameplayElement():MobileEntity(),FocusableElement()
{
	movingState = IDLE;
	HateWalls = true;
	heavy = false;
}

MobileGameplayElement::MobileGameplayElement(bool hw, bool hv) :MobileEntity(), FocusableElement()
{
	movingState = IDLE;
	HateWalls = hw;
	heavy = hv;
}

MobileGameplayElement::MobileGameplayElement(bool hateW, bool heavii, bool fly, double Speed, bool TraverseBlock, bool TraverseMur, bool MarcheSurBlock, bool traversable, Vector2f position, Texture texture, IntRect textrect)
	:FocusableElement(traversable),MobileEntity(fly, Speed, TraverseBlock, TraverseMur, MarcheSurBlock, position, texture, textrect)
{
	cout << "traversable" << traversable << endl;
	movingState = IDLE;
	HateWalls = hateW;
	heavy = heavii;
}

MobileGameplayElement::MobileGameplayElement(bool hateW, bool heavii, bool fly, double Speed, bool TraverseBlock, bool TraverseMur, bool MarcheSurBlock, bool traversable, int intervalframe, Vector2f position, Texture texture, IntRect textrect) 
	:FocusableElement(traversable),MobileEntity(fly, Speed, TraverseBlock, TraverseMur, MarcheSurBlock, intervalframe, position, texture, textrect)
{
	cout << "traversable" << traversable << endl;
	movingState = IDLE;
	HateWalls = hateW;
	heavy = heavii;
}

enum MovingState MobileGameplayElement::getMovingState()
{
	return movingState;
}

void MobileGameplayElement::setMovingState(enum MovingState m)
{
	movingState = m;
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
