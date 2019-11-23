#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum Direction { HAUT, BAS, GAUCHE, DROITE };

enum ElementTypes {
	VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, ONEWAY_DROITE,
	PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL,
	ANIMAL_COULEUR1, ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN
};

enum GameColor {
	NOCOLOR,ROUGE,BLEU,JAUNE
};



class GameObject
{
protected:
	Sprite sprite;
	IntRect textureRect;
	Texture texture;
public:
	GameObject();
	GameObject(Vector2f, Texture, IntRect);
	void drawMe(RenderWindow&);
	virtual void update();


	Sprite* getSprite();
	void setSprite(Sprite);
	IntRect* getTextureRect();
	void setTextureRect(IntRect);
	Texture* getTexture();
	void setTexture(Texture);
};

