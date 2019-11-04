#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Mur.h"
#include "Player.h"
#include "OneWay.h"

using namespace std;
using namespace sf;



struct ElementContainer
{
	ElementTypes type;
	String Name;
	Mur mur;
	Player player;
	OneWay oneway;
	FloatRect getGlobalBounds() {
		switch (this->type)
		{
			/**
		case VIDE:
			break;/**/
		case MUR:
			return this->mur.getGlobalBounds();
			break;
		
		case ONEWAY:
			return this->oneway.getGlobalBounds();
			break;
		/**
		case ONEWAY_HAUT:
			break;
		case ONEWAY_BAS:
			break;
		case ONEWAY_GAUCHE:
			break;
		case ONEWAY_DROITE:
			break;
		case PIQUE:
			break;
		case SWITCH:
			break;
		case GOAL:
			break;
		case ROCHER:
			break;
		case BOUTEILLE:
			break;
		case BOUTEILLE_VIVANTE:
			break;
		case BOUTEILLE_COULEUR1:
			break;
		case BOUTEILLE_COULEUR2:
			break;
		case BOUTEILLE_COULEUR3:
			break;
		case BLOC:
			break;
		case BLOC_VIVANT:
			break;
		case BLOC_COULEUR1:
			break;
		case BLOC_COULEUR2:
			break;
		case BLOC_COULEUR3:
			break;
		case ANIMAL:
			break;
		case ANIMAL_COULEUR1:
			break;
		case ANIMAL_COULEUR2:
			break;
		case ANIMAL_COULEUR3:
			break;/**/
		case PLAYER:
			return this->player.getGlobalBounds();
			break;/**
		case SPAWN:
			break;/**/
		default:
			cout << "Unknown Type on ElementContainer.getGlobalBounds where type = " << this->type << endl;
			return FloatRect(0, 0, 0, 0);
			break;
		}
	}
};



class Scene
{
protected:
	int score;
	vector <ElementContainer> gameObjects;
	ElementContainer playerContainer;
	Vector2f spawnPoint;
public:
	Scene();
	Scene(int, vector <vector <int>>);
	Scene(int, vector <ElementContainer>, Vector2f , ElementContainer);

	void generate(vector <vector <int>>);
	void draw(RenderWindow&);
	bool testCollide(ElementContainer&, vector < ElementContainer>&, Direction);
	void update();

	int getScore();
	void setScore(int);
	vector <ElementContainer> getGameObjects();
	void setGameObjects(vector <ElementContainer>);
	ElementContainer getPlayer();
	void setPlayer(ElementContainer);
	Vector2f getSpawnPoint();
	void setSpawnPoint(Vector2f);
};

