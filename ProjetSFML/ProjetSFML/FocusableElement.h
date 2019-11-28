#pragma once
#include "GameEntity.h"

class FocusableElement:public GameEntity// Classe mère des éléments que l'on peut cibler pour interagier
{
protected:
	//Pas encore mis en application
	bool focused = false;
	bool locked = false;

public:
	/* CONSTRUCTEURS */
	FocusableElement();//Constructeur standard
	/*
		Les constructeurs suivant servent pour etre intégrés dans la construction de classes filles
	*/
	FocusableElement(bool);
	FocusableElement(bool, bool, bool);
	FocusableElement(bool, Vector2f, Texture, IntRect);
	FocusableElement(bool, int, Vector2f, Texture, IntRect);

	/* GETER SETER */
	bool getFocused();
	void setFocused(bool);
	bool getLocked();
	void setLocked(bool);
};

