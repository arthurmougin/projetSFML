#pragma once
#include "GameEntity.h"

class Scene;
class Bouteille;



class Switch:public GameEntity
{
public:
	Switch();
	Switch(Vector2f, Texture, IntRect);

	void interact(Scene *);

};

