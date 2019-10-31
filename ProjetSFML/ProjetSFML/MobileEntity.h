#pragma once
#include "GameObject.h"
#include "Mur.h"
#include "Player.h"

enum ElementTypes {
	VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, ONEWAY_DROITE,
	PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL,
	ANIMAL_COULEUR1, ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN
};

struct ElementContainer
{
	ElementTypes type;
	String Name;
	Mur mur;
	Player player;
};

enum Direction {HAUT, BAS, GAUCHE, DROITE};

class MobileEntity:public GameObject //désigne tout élément qui se déplace de manière autonome
{
protected:
	bool flying;//pour les blocks
	float speed;
	Vector2f acceleration;
	Vector2f direction;
	bool TraverseBlock;//les animaux ne traversent pas les blocks
	bool TraverseMur;//les Blocks traversent les murs
	bool MarcheSurBlock;//le personnage en mode Rocher tombe au travers des blocks
	float Hauteur;// 0 au sol, 1++ quand on est en air
	Sprite Fantome;

public:
	MobileEntity();
	MobileEntity(bool, float, bool, bool,bool);
	MobileEntity(bool, float, Vector2f, Vector2f,bool, bool, bool, float);

	bool testCollision(int, float, vector <ElementContainer>);
	void moveTo(int, float , vector <ElementContainer>);
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

