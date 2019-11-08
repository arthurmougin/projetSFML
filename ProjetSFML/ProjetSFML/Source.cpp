#include <iostream>
#include <string>
#include <vector>
#include <SFML/audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameMaster.h"

using namespace std;
using namespace sf;

int main(void) {
	GameMaster MJ;
	/*
	VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, 
	ONEWAY_DROITE, PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, 
	BOUTEILLE_VIVANTE, BOUTEILLE_COULEURMUR, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEURMUR, 
	BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL, ANIMAL_COULEURMUR, 
	ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN
	*/
	MJ.addMap(Map({

		{VIDE,	VIDE,	VIDE,	VIDE,	VIDE},

		{VIDE,	MUR,	MUR,	MUR,	VIDE},

		{VIDE,	MUR,	MUR,	MUR,	VIDE},

		{VIDE,	MUR,	MUR,	MUR,	VIDE},

		{VIDE,	VIDE,	VIDE,	VIDE,	VIDE},

	}));

	MJ.run();
}