#pragma once
#include "GameEntity.h"

class Goal :public GameEntity
{

public:
	/* CONSTRUCTEURS */
	Goal();//Constructeur standard
	Goal(Vector2f, Texture, IntRect);//Constructeur utilis� dans la g�n�ration de la scene 
};

