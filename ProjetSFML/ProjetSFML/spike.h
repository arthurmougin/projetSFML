#pragma once
#include "GameEntity.h"


class spike :public GameEntity//element qui tue le joueur s'il le touche
{
public:
	/* CONSTRUCTEURS */
	spike();//Constructeur standard
	spike(Vector2f, Texture, IntRect);//Constructeur utilisé dans la génération de la scene 
};

