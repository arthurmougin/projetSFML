#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::GameObject(Vector2f vect, Texture tex, IntRect rect)
{
	sprite.setPosition(vect);
	setTexture(tex);
	setTextureRect(rect);
}

void GameObject::drawMe(RenderWindow &R)
{
	//cout << "DrawMe\n";
	R.draw(sprite);
}

void GameObject::update()
{
}

Sprite* GameObject::getSprite()
{
	return &sprite;
}

void GameObject::setSprite(Sprite s)
{
	sprite = s;
}

IntRect* GameObject::getTextureRect()
{
	return &textureRect;
}

void GameObject::setTextureRect(IntRect t)
{
	textureRect = t;
	sprite.setTextureRect(textureRect);
}

Texture* GameObject::getTexture()
{
	return &texture;
}

void GameObject::setTexture(Texture t)
{
	texture = t;
	sprite.setTexture(texture);
}
