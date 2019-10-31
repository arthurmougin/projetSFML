#pragma once
#include "GameObject.h"
class Mur:public GameObject
{
public:
	Mur();
	Mur(Vector2f);
	Mur(Vector2f, Texture, IntRect);
	//void update();
};

