#pragma once
#include "PaintableElement.h"
class Bouteille:public PaintableElement
{
public:
	Bouteille();
	Bouteille(GameColor);
	Bouteille(bool);
	Bouteille(bool, GameColor);
	Bouteille(bool, Vector2f, Texture, IntRect);
	Bouteille(bool, GameColor, Vector2f, Texture, IntRect);
};

