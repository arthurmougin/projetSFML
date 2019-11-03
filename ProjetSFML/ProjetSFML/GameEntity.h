#pragma once
#include "GameObject.h";



class GameEntity : public GameObject
{
protected:
	bool traversable;

public:
	GameEntity();
	GameEntity(bool);

	bool getTraversable();
	void setTraversable(bool);

	virtual void interact(string) = 0;
	virtual void ActOnCollide();


};

