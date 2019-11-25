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

GameObject::GameObject(int anim, Vector2f vect, Texture tex, IntRect rect)
{
	animationframes = anim;
	sprite.setPosition(vect);
	setTexture(tex);
	setTextureRect(rect);
}

void GameObject::drawMe(RenderWindow &R)
{
	//cout << "DrawMe\n";
	if (animationframes >= 2 && innerAnnimationClock.getElapsedTime().asSeconds() >= frequence) {

		animationStep++;
		animationStep = (animationStep % animationframes) ; 
		IntRect tr = sprite.getTextureRect();
		tr.left = textureRect.left + (animationStep * tr.width);
		sprite.setTextureRect(tr);
		innerAnnimationClock.restart();
	}
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

int GameObject::getAnimationframes()
{
	return animationframes;
}

void GameObject::setAnimationframes(int i)
{
	animationframes = i;
}

Color getColorFromEnum(GameColor gc) {
	switch (gc)
	{
	case GameColor::NOCOLOR:
		return Color::White;
		break;
	case GameColor::ROUGE:
		return Color::Red;
		break;
	case GameColor::BLEU:
		return Color::Blue;
		break;
	case GameColor::JAUNE:
		return Color::Yellow;
		break;
	default:
		return Color::White;
		break;
	}

}

GameColor getEnumFromColor(Color C) {
	if (C == Color::Red) {
		return GameColor::ROUGE;
	}
	else if (C == Color::Blue) {
		return GameColor::BLEU;
	}
	else if (C == Color::Yellow) {
		return GameColor::JAUNE;
	}
	else {
		return GameColor::NOCOLOR;
	}
}