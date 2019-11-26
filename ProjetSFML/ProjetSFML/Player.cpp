#pragma once
#include "Player.h"
#include "Scene.h"

Player::Player() :MobileEntity()
{
	bringSomething = false;
	bringElement = NULL;
	bringColor = GameColor::NOCOLOR;
}

Player::Player(Vector2f pos, Texture tex, IntRect rect) :MobileEntity( 2, pos, tex, rect)
{
	bringSomething = false;
	bringElement = NULL;
	bringColor = GameColor::NOCOLOR;
}

void Player::update(Scene*scene)
{
	//cout << endl;
	/*
	setup original :
		--
			if keyboard Haut && !TestCollide Haut
				moveto Up

			if keyboard Bas && !TestCollide Bas
				moveto Down

			if playerhauteur!=0 &&é && TestCollide Haut
				Kill velocity

			if playerhauteur!=0 && TestCollide Bas
				Faire attérir le personnage

			if playerhauteur==0 && !TestCollide Bas
				Faire tomber le personnage
		--
		avantages = propreté
		defaut = TestCollide est Très gourmand

		La nouvelle architecture peut paraitre bordellique, mais elle a l'avantage de limiter les calls de TestCollide

	*/

	//Input dans les 4 directions
	initDirection();
	bool testcollhaut, testcollbas;
	testcollhaut = scene->testCollide(this, Direction::HAUT);
	if (getHauteur() == 0 && Keyboard::isKeyPressed(Keyboard::Up) && !testcollhaut) {
		//cout << "Up" << endl;
		scene->setScore(scene->getScore() -3);
		moveTo(Direction::HAUT);
	}
	//si la hauteur du personnage est superieur à 0, on vérifie s'il ne s'est pas cogné la tete
	if (getHauteur() != 0 && testcollhaut) {
		setAcceleration(Vector2f(0, 0));
		float localY = getSprite()->getPosition().y, LocalDelta;
		localY = (int(localY) % 160) + localY - int(localY);
		//cout << "localy : " << localY << endl;
		if (localY < 80) {
			localY = -localY;
		}
		else {
			localY = 160 - localY;
		}
		getSprite()->move(Vector2f(0, localY));
	}
	testcollbas = scene->testCollide(this, Direction::BAS);

	if (testcollbas) {
		if (getHauteur() != 0) {
			setHauteur(0);
			float localY = getSprite()->getPosition().y, LocalDelta;
			localY = (int(localY) % 160) + localY - int(localY);
			cout << "localy : " << localY << endl;
			if (localY < (80)) {
				localY = -localY + 32;
			}
			else {
				localY = 160 - localY - 32;
			}
			getSprite()->move(Vector2f(0, localY));
		}
	}
	else if (getHauteur() == 0) {
		setHauteur(1);
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && !scene->testCollide(this, Direction::GAUCHE)) {
		scene->setScore(scene->getScore() - 1);
		//cout << "Left" << endl;
		moveTo(Direction::GAUCHE);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && !scene->testCollide(this, Direction::DROITE))
	{
		scene->setScore(scene->getScore() - 1);
		//cout << "Right" << endl;
		moveTo(Direction::DROITE);
	}

	updatePos(9.8 / 12);
}

FloatRect Player::getInteractionBox()
{
	FloatRect gb = sprite.getGlobalBounds();
	interactionBox.top = gb.top - ((interactionBox.height - gb.height)/2);
	if (sprite.getTextureRect().top == this->textureRect.top) {
		interactionBox.left = gb.left + gb.width;
	}
	else {
		interactionBox.left = gb.left - interactionBox.width;
	}
	return interactionBox;
}

void Player::moveTo(Direction d)
{
	MobileEntity::moveTo(d);
	IntRect tr = this->sprite.getTextureRect();
	if (d == Direction::DROITE) {
		tr.top = this->textureRect.top;
	}
	else if (d == Direction::GAUCHE) {
		tr.top = this->textureRect.top + 32;
	}
	this->sprite.setTextureRect(tr);
}

bool Player::getBringSomething()
{
	return bringSomething;
}

void Player::setBringSomething(bool b)
{
	bringSomething = b;
	bringElement = NULL;
	bringColor = NOCOLOR;
	sprite.setColor(getColorFromEnum(bringColor));
}

GameObject* Player::getBringElement()
{
	return bringElement;
}

void Player::setBringElement(GameObject* be)
{
	bringElement = be;
	bringSomething = true;
}

GameColor Player::getBringColor()
{
	return bringColor;
}

void Player::setBringColor(GameColor b)
{
	bringColor = b;
	sprite.setColor(getColorFromEnum(bringColor));
	if( b == NOCOLOR)
		bringSomething = false;
	else
		bringSomething = true;
}
