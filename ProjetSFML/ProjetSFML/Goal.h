#pragma once
#include "GameEntity.h"

class Goal :public GameEntity
{

public:
	/* CONSTRUCTEURS */
	Goal();//Constructeur standard
	Goal(Vector2f, Texture, IntRect);//Constructeur utilisé dans la génération de la scene 
};

