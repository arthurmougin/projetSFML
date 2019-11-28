#pragma once
#include "PaintableElement.h"
class Bouteille:public PaintableElement
{
public:
	/* CONSTRUCTEURS */
	Bouteille();//Constructeur standard
	Bouteille(bool, Vector2f, Texture, IntRect);//Constructeur utilisable dans la génération de la scene
	Bouteille(bool, GameColor, Vector2f, Texture, IntRect);//Constructeur utilisable dans la génération de la scene
	/* Constructeurs alternatifs */
	Bouteille(GameColor);
	Bouteille(bool);
	Bouteille(bool, GameColor);
};

