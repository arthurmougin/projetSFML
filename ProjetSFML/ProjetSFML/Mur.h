#pragma once
#include "GameObject.h"
class Mur:public GameObject
{
public:
	/* CONSTRUCTEURS */
	Mur();//Constructeur standard
	Mur(Vector2f, Texture, IntRect);//Constructeur utilis� dans la g�n�ration de la scene  
	/* Constructeurs alternatifs */
	Mur(Vector2f);
	//void update();
};

