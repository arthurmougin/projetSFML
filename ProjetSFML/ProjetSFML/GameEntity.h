#pragma once
#include "GameObject.h"



class GameEntity : public GameObject
{
protected:
	bool traversable;

public:
	GameEntity();
	GameEntity(bool);
	GameEntity(bool, Vector2f, Texture, IntRect);

	bool getTraversable();
	void setTraversable(bool);
	

	virtual void interact();

};

