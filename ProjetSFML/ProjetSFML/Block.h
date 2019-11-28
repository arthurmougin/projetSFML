#pragma once
#include "MobileGameplayElement.h"

class Block :public MobileGameplayElement
{
protected:
	bool vivant = false;
	
public:
	/* CONSTRUCTEURS */
	Block();//Constructeur standard
	Block(Vector2f, Texture, IntRect);//Constructeurs utilisable dans la génération de la scene
	Block(bool,Vector2f, Texture, IntRect);//Constructeurs utilisable dans la génération de la scene
	Block(GameColor, Vector2f, Texture, IntRect);//Constructeurs utilisable dans la génération de la scene
	Block(bool, GameColor,Vector2f, Texture, IntRect);//Constructeurs utilisable dans la génération de la scene 
	/* Constructeurs alternatifs */
	Block(GameColor);
	Block(bool);
	Block(bool, GameColor);

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void update(Scene*);
	
	/* GETER SETER */
	bool getVivant();
	void setVivant(bool);
	
};

