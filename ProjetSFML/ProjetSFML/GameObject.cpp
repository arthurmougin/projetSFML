#include "GameObject.h"

GameObject::GameObject():Sprite()
{

}

void GameObject::drawMe(RenderWindow &R)
{
	R.draw(*this);
}

void GameObject::update()
{
}
