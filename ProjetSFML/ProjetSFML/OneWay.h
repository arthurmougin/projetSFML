#pragma once
#include "GameEntity.h"
class OneWay:public GameEntity
{
protected:
	enum Direction blockDirection;//Direction bloquée par le OneWay

public:
	/* CONSTRUCTEURS */
	OneWay();//Constructeur standard
	OneWay(Direction,Vector2f, Texture, IntRect);//Constructeur utilisé dans la génération de la scene
	/* Constructeurs alternatifs */
	OneWay(Direction);
	
	/* GETER SETER */
	Direction getBlockDirection();
	void setBlockDirection(Direction);
};

