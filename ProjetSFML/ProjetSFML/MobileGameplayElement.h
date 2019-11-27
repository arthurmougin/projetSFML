#pragma once
#include "PaintableElement.h"

enum MovingState {
	IDLE,MOVING_LEFT,MOVING_RIGHT, MOVING_UP, MOVING_DOWN,
	JUMPING,FALLING, MOVING_UP_LEFT, MOVING_UP_RIGHT, MOVING_DOWN_LEFT, MOVING_DOWN_RIGHT,
};

class MobileGameplayElement: public PaintableElement
{
protected:
	enum MovingState movingState;
	bool HateWalls;
	bool heavy;

	Clock SwitchMouvementClock;
	double SwitchMouvementDelay = 2; //in seconds

	/*

	1/2 DUPLIQUE DE MobileEntity
	propriétés

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
	MobileGameplayElement();
	MobileGameplayElement(bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, bool, bool, double, bool, bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, Vector2f, Texture, IntRect, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, Vector2f, Texture, IntRect, bool, bool, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, int, Vector2f, Texture, IntRect, GameColor);
	MobileGameplayElement(bool, bool, bool, double, bool, bool, bool, bool, int, Vector2f, Texture, IntRect, bool, bool, GameColor);

	void update(Scene*);

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

	void moveTo(Direction);
	void updatePos(double);//Gravity
	void initDirection();

	Sprite getUpdatedFantome(Direction);

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

