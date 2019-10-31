#include "GameObject.h"

GameObject::GameObject():Sprite()
{
}

void GameObject::draw(RenderWindow &R)
{
	R.draw(*this);
}

void GameObject::update()
{
}
