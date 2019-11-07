#pragma once
#include "GameObject.h"


class MobileEntity:public GameObject //désigne tout élément qui se déplace de manière autonome
{
protected:
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
	MobileEntity();
	MobileEntity(bool, double, bool, bool,bool);
	MobileEntity(bool, double, Vector2f, Vector2f,bool, bool, bool, double);

	void moveTo(Direction);
	void updatePos(double);//Gravity

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

