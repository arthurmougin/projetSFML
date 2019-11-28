#pragma once
#include "GameObject.h"
class Mur:public GameObject
{
public:
	/* CONSTRUCTEURS */
	Mur();//Constructeur standard
	Mur(Vector2f, Texture, IntRect);//Constructeur utilisé dans la génération de la scene  
	/* Constructeurs alternatifs */
	Mur(Vector2f);
	//void update();
};

