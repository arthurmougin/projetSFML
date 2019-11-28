#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/* ENUMERATEURS */
enum class Direction { HAUT, BAS, GAUCHE, DROITE }; //	Les directions de deplacement possibles

enum ElementTypes { //	Les éléments que l'on peut retrouver dans une carte matrice
	VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, ONEWAY_DROITE,
	PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL,
	ANIMAL_COULEUR1, ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN
};

enum MovingState { //	Les Mouvement possibles pour les entités non joueur
	IDLE, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN,
	JUMPING, FALLING, MOVING_UP_LEFT, MOVING_UP_RIGHT, MOVING_DOWN_LEFT, MOVING_DOWN_RIGHT,
};

enum GameColor { //	Les couleurs disponible (NOCOLOR = blanc, ROUGE, BLEU et JAUNE)
	NOCOLOR,ROUGE,BLEU,JAUNE
};

//Classes utilitaires pour convertir les enums gamecolor en couleur
Color getColorFromEnum(GameColor);
GameColor getEnumFromColor(Color);

class Scene;

class GameObject
{
protected:
	Sprite sprite;
	IntRect textureRect;
	Texture texture;
	int animationframes = 1;
	Clock innerAnnimationClock;
	float frequence = 0.5;
	int animationStep = 0;
public:
	/* CONSTRUCTEURS */
	GameObject();//Constructeur standard
	/*
		Les constructeurs suivant servent pour etre intégrés dans la construction de classes filles
	*/
	GameObject(Vector2f, Texture, IntRect);
	GameObject(int, Vector2f, Texture, IntRect);

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void drawMe(RenderWindow&);
	virtual void update(Scene *);

	/* GETER SETER */
	Sprite* getSprite();
	void setSprite(Sprite);
	IntRect* getTextureRect();
	void setTextureRect(IntRect);
	Texture* getTexture();
	void setTexture(Texture);
	int getAnimationframes();
	void setAnimationframes(int);
};

