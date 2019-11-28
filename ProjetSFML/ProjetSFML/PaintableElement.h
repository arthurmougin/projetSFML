#pragma once
#include "FocusableElement.h"

class PaintableElement:public FocusableElement //classe mere des éléments interagissant avec la couleur
{
protected:
	bool paintable = false; // si l'on peut appliquer de la couleur ou non sur l'objet
	enum GameColor color = GameColor::NOCOLOR; // la couleur stockée de l'élément
	bool inhalable = true; // si l'on peut prendre de la couleur ou non de l'objet
public:
	/* CONSTRUCTEURS 
	*/
	PaintableElement();//Constructeur standard
	/*
		Les constructeurs suivant servent pour etre intégrés dans la construction de classes filles
	*/
	PaintableElement(bool, bool);
	PaintableElement(bool, bool, bool);
	PaintableElement(bool, bool, bool, GameColor);
	PaintableElement(bool, bool, bool, Vector2f, Texture, IntRect);
	PaintableElement(bool, bool, bool, int, Vector2f, Texture, IntRect);
	PaintableElement(bool, bool, GameColor);
	PaintableElement(bool, bool, GameColor, bool, Vector2f, Texture, IntRect);
	PaintableElement(bool, bool, GameColor, bool, int, Vector2f, Texture, IntRect);

	/* GETER SETER */
	bool getPaintable();
	void setPaintable(bool);
	GameColor getColor();
	void setColor(GameColor);
	bool getInhalable();
	void setInhalable(bool);
};

