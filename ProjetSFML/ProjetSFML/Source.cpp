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
	Font myFont;
	if (!myFont.loadFromFile("PressStart2P-Regular.ttf")) {
		cout << "Font failed to load" << endl;
	}
	MJ.setFont(&myFont);
	/*
	VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, 
	ONEWAY_DROITE, PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, 
	BOUTEILLE_VIVANTE, BOUTEILLE_COULEURMUR, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, 
	BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL, ANIMAL_COULEUR1, 
	ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN
	*/
	MJ.addMap(Map({

		{MUR,	MUR,	MUR,			MUR,		MUR,		MUR,			MUR,			MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR},

		{MUR,	VIDE,	VIDE,			VIDE,		VIDE,		VIDE,			VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	VIDE,			VIDE,		VIDE,		VIDE,			VIDE,			VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	VIDE,			VIDE,		VIDE,		VIDE,			VIDE,			VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	ONEWAY_HAUT,	VIDE,		VIDE,		VIDE,			VIDE,			VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	VIDE,			ONEWAY_BAS,	VIDE,		VIDE,			VIDE,			VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	VIDE,			VIDE,		VIDE,		VIDE,			ONEWAY_HAUT,	VIDE,	VIDE,		VIDE,	ONEWAY_HAUT,	VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	ONEWAY_HAUT,	VIDE,		VIDE,		ONEWAY_GAUCHE,	ONEWAY_DROITE,	VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},
			
		{MUR,	VIDE,	VIDE,			VIDE,		ONEWAY_BAS,	VIDE,			ONEWAY_BAS,		VIDE,	ONEWAY_BAS,	VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	VIDE,			VIDE,		VIDE,		VIDE,			VIDE,			VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	ONEWAY_HAUT,	VIDE,		SPAWN,		VIDE,			VIDE,			VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	VIDE,	VIDE,			VIDE,		VIDE,		VIDE,			VIDE,			VIDE,	VIDE,		VIDE,	VIDE,			VIDE,	VIDE,	MUR},

		{MUR,	MUR,	MUR,			MUR,		MUR,		MUR,			MUR,			MUR,	MUR,		MUR,	MUR,			MUR,	MUR,	MUR},

	}));

	MJ.run();
}