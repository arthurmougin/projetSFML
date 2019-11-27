#pragma once
#include "MobileGameplayElement.h"

class Block :public MobileGameplayElement
{
protected:
	bool vivant = false;
	
public:
	Block();
	Block(GameColor);
	Block(bool);
	Block(bool, GameColor);
	Block(Vector2f, Texture, IntRect);
	Block(bool,Vector2f, Texture, IntRect);
	Block(GameColor, Vector2f, Texture, IntRect);
	Block(bool, GameColor,Vector2f, Texture, IntRect);

	bool getVivant();
	void setVivant(bool);

};

