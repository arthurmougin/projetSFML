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
	GameObject* testcollhaut, *testcollbas;

	testcollhaut = scene->testCollide(this, Direction::HAUT);

	if (getHauteur() == 0 && Keyboard::isKeyPressed(Keyboard::Up) && !testcollhaut) {
		//cout << "Up" << endl;
		scene->setScore(scene->getScore() -3);
		moveTo(Direction::HAUT);
	}
	//si la hauteur du personnage est superieur à 0 et qu'il monte, on vérifie s'il ne s'est pas cogné la tete
	//Attention, il faut etre sur que son mouvement est montant
	if (getHauteur() != 0 && acceleration.y < 0 && testcollhaut) {
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
	if (testcollbas) {//s'il descendais, et qu'il est entré en collision avec le sol, 
		//alors on le colle au dessus de l'élément collidé
		if (getHauteur() != 0 && acceleration.y > 0) {
			cout << "snapping" << endl;
			setHauteur(0);
			FloatRect colliderGB = testcollbas->getSprite()->getGlobalBounds();
			FloatRect localGB = sprite.getGlobalBounds();

			float LocalDelta = (colliderGB.top - localGB.height) - localGB.top;
			sprite.move(Vector2f(0, LocalDelta));
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
	//on regarde le type de texture sur le joueur (si c'est la texture droite ou la texture gauche)
	if (sprite.getTextureRect().top == this->textureRect.top) {
		// right
		interactionBox.left = gb.left + gb.width;
	}
	else {
		//left
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
	/**
	bringElement = NULL;
	bringColor = NOCOLOR;
	sprite.setColor(getColorFromEnum(bringColor));
	/**/
}

GameObject* Player::getBringElement()
{
	return bringElement;
}

void Player::setBringElement(GameObject* be)
{
	if (be != NULL)
	{
		bringElement = be;
		bringSomething = true;
		bringColor = NOCOLOR;

		if (dynamic_cast<Rocher*>(bringElement)) {
			textureRect.top = 3 * 2 * textureRect.height;
		}
	}
	else {
		if (bringElement != NULL) {// Si il y a un élément, on le replace dans la scene
			placeBringElement();
		}
		bringElement = be;
		bringSomething = false;
		textureRect.top = 0 * 2 * textureRect.height;
	}
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

void Player::placeBringElement()
{
	Vector2f newPos = sprite.getPosition();
	FloatRect gb = sprite.getGlobalBounds();
	//on regarde le type de texture sur le joueur (si c'est la texture droite ou la texture gauche)
	newPos.y = gb.top + (gb.height / 4);
	if (sprite.getTextureRect().top == this->textureRect.top) {
		// right
		newPos.x = gb.left + gb.width;
	}
	else {
		// 
		newPos.x = gb.left - bringElement->getSprite()->getGlobalBounds().width;
	}
	bringElement->getSprite()->setPosition(newPos);


}
