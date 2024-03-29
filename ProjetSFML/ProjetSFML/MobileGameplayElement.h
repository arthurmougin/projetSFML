#pragma once
#include "PaintableElement.h"


class MobileGameplayElement: public PaintableElement
{
protected:
	enum MovingState movingState = IDLE;
	bool HateWalls;
	bool heavy;

	Clock SwitchMouvementClock;
	double SwitchMouvementDelay = 2; //in seconds

	/*

	1/2 DUPLIQUE DE MobileEntity
	propri�t�s

	*/
	bool flying;//pour les blocks
	double speed;
	Vector2f acceleration;
	Vector2f direction;
	bool TraverseBlock;// les animaux ne traversent pas les blocks
	bool TraverseMur;// les Blocks traversent les murs
	bool MarcheSurBlock;// le personnage en mode Rocher tombe au travers des blocks
	double Hauteur;// 0 au sol, 1++ quand on est en air
	Sprite Fantome;



public:
	/* CONSTRUCTEURS */
	MobileGameplayElement();//Constructeur standard
	/*
		Les constructeurs suivant servent pour etre int�gr�s dans la construction de classes filles
	*/
	MobileGameplayElement(bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, bool, bool, double, bool, bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, Vector2f, Texture, IntRect, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, Vector2f, Texture, IntRect, bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, int, Vector2f, Texture, IntRect, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, int, Vector2f, Texture, IntRect, bool, bool, GameColor);

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void update(Scene*);

	/* GETER SETER */
	enum MovingState getMovingState();
	void setMovingState(enum MovingState);
	bool getHateWalls();
	void setHateWalls(bool);
	bool getHeavy();
	void setHeavy(bool);


	/*

	2/2 DUPLIQUE DE MobileEntity
	Fonctions
	
	*/

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void moveTo(Direction);
	void updatePos(double);//Gravity
	void initDirection();
	Sprite getUpdatedFantome(Direction);

	/* GETER SETER */
	bool getFlying();
	void setFlying(bool);

	double getSpeed();
	void setSpeed(double);

	Vector2f getAcceleration();
	void setAcceleration(Vector2f);

	Vector2f getDirection();
	void setDirection(Vector2f);

	bool getTraverseBlock();
	void setTraverseBlock(bool);

	bool getTraverseMur();
	void setTraverseMur(bool);

	bool getMarcheSurBlock();
	void setMarcheSurBlock(bool);

	double getHauteur();
	void setHauteur(double);

	Sprite getFantome();
	void setFantome(Sprite);
};

