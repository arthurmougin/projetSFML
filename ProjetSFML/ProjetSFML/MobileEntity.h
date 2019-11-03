#pragma once
#include "GameObject.h"


class MobileEntity:public GameObject //désigne tout élément qui se déplace de manière autonome
{
protected:
	bool flying;//pour les blocks
	float speed;
	Vector2f acceleration;
	Vector2f direction;
	bool TraverseBlock;// les animaux ne traversent pas les blocks
	bool TraverseMur;// les Blocks traversent les murs
	bool MarcheSurBlock;// le personnage en mode Rocher tombe au travers des blocks
	float Hauteur;// 0 au sol, 1++ quand on est en air
	Sprite Fantome;

public:
	MobileEntity();
	MobileEntity(bool, float, bool, bool,bool);
	MobileEntity(bool, float, Vector2f, Vector2f,bool, bool, bool, float);

	void moveTo(int);
	void updatePos(float);//Gravity

	bool getFlying();
	void setFlying(bool);

	float getSpeed();
	void setSpeed(float);

	Vector2f getAcceleration();
	void setAcceleration(Vector2f);

	Vector2f getDirection();
	void setDirection(Vector2f);

	bool getTraverseBlock();
	void setTraverseBlock(bool);

	bool getMarcheSurBlock();
	void setMarcheSurBlock(bool);

	float getHauteur();
	void setHauteur(float);

};

