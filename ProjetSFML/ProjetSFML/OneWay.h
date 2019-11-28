#pragma once
#include "GameEntity.h"
class OneWay:public GameEntity
{
protected:
	enum Direction blockDirection;//Direction bloqu�e par le OneWay

public:
	/* CONSTRUCTEURS */
	OneWay();//Constructeur standard
	OneWay(Direction,Vector2f, Texture, IntRect);//Constructeur utilis� dans la g�n�ration de la scene
	/* Constructeurs alternatifs */
	OneWay(Direction);
	
	/* GETER SETER */
	Direction getBlockDirection();
	void setBlockDirection(Direction);
};

