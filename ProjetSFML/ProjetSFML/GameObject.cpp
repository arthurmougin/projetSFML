#include "GameObject.h"

GameObject::GameObject():Sprite()
{

}

GameObject::GameObject(Vector2f vect, Texture tex, IntRect rect):Sprite(tex,rect)
{
	setPosition(vect);
}

void GameObject::drawMe(RenderWindow &R)
{
	R.draw(*this);
}

void GameObject::update()
{
}
