#pragma once
#include "GameObject.h"



class GameEntity : public GameObject//classe m�re des objets non Joueur
{
protected:
	bool traversable; //Si un �l�ment est transparent aux collisions

public:
	/* CONSTRUCTEURS */
	GameEntity();//Constructeur standard
	/*
		Les constructeurs suivant servent pour etre int�gr�s dans la construction de classes filles
	*/
	GameEntity(bool);
	GameEntity(bool, Vector2f, Texture, IntRect);
	GameEntity(bool, int, Vector2f, Texture, IntRect);

	/* FONCTIONS MEMBRES DE LA CLASSE */
	virtual void interact();

	/* GETER SETER */
	bool getTraversable();
	void setTraversable(bool);
	


};

