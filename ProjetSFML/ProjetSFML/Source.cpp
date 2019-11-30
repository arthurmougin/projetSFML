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
		//cout << "Font failed to load" << endl;
	}
	MJ.setFont(&myFont);
	/*
	VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, 
	ONEWAY_DROITE, PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, 
	BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, PLAYER, SPAWN,
	
	BLOC, BLOC_VIVANT, BLOC_COULEUR1, 
	BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL, ANIMAL_COULEUR1, 
	ANIMAL_COULEUR2, ANIMAL_COULEUR3, 
	*/

	/**
	MJ.addMap(Map(1500, {

		{MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,			MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	SPAWN,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	SWITCH,	VIDE,	VIDE,	VIDE,	BOUTEILLE,	MUR},

		{MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,			MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,		MUR},

		}));
	/**/


	MJ.addMap(Map(2000,{
			
		{MUR,	MUR,	MUR,	MUR,			MUR,	MUR,			MUR,			MUR,			MUR,	MUR,			MUR,	MUR,				MUR,			MUR,			MUR,			MUR,				MUR,	MUR,	MUR,			MUR,				MUR,			MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR},

		{MUR,	MUR,	MUR,	MUR,			MUR,	MUR,			MUR,			MUR,			MUR,	MUR,			MUR,	MUR,				MUR,			MUR,			MUR,			MUR,				MUR,	MUR,	MUR,			MUR,				MUR,			MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	VIDE,			VIDE,	VIDE,			VIDE,			VIDE,			VIDE,	VIDE,			MUR,	VIDE,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	VIDE,			VIDE,				VIDE,			VIDE,	VIDE,	MUR,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	GOAL,			VIDE,	VIDE,			VIDE,			VIDE,			VIDE,	VIDE,			VIDE,	VIDE,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	VIDE,			VIDE,				VIDE,			VIDE,	VIDE,	MUR,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	VIDE,			VIDE,	VIDE,			VIDE,			VIDE,			VIDE,	ONEWAY_DROITE,	VIDE,	VIDE,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	VIDE,			VIDE,				VIDE,			VIDE,	VIDE,	MUR,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	GOAL,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	ONEWAY_HAUT,	VIDE,	VIDE,			VIDE,			VIDE,			VIDE,	VIDE,			VIDE,	VIDE,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	VIDE,			VIDE,				VIDE,			VIDE,	VIDE,	MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	VIDE,			VIDE,	VIDE,			VIDE,			VIDE,			VIDE,	VIDE,			MUR,	VIDE,				VIDE,			VIDE,			VIDE,			BOUTEILLE,			VIDE,	VIDE,	VIDE,		 	BOUTEILLE_COULEUR3,	VIDE,			VIDE,	VIDE,	MUR,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	VIDE,			VIDE,	BLOC_COULEUR2,	VIDE,			VIDE,			VIDE,	VIDE,			MUR,	ONEWAY_HAUT,		ONEWAY_HAUT,	ONEWAY_HAUT,	ONEWAY_HAUT,	ONEWAY_HAUT,		VIDE,	VIDE,	ONEWAY_HAUT,	ONEWAY_HAUT,		VIDE,			VIDE,	VIDE,	MUR,	VIDE,	VIDE,	GOAL,	GOAL,	GOAL,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	ONEWAY_HAUT,	VIDE,	VIDE,			ONEWAY_GAUCHE,	ONEWAY_DROITE,	VIDE,	VIDE,			MUR,	VIDE,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	VIDE,			VIDE,				VIDE,			VIDE,	VIDE,	MUR,	VIDE,	VIDE,	GOAL,	GOAL,	GOAL,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	VIDE,			VIDE,	ONEWAY_BAS,		VIDE,			ONEWAY_BAS,		VIDE,	ONEWAY_BAS,		MUR,	VIDE,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	VIDE,			VIDE,				VIDE,			VIDE,	VIDE,	MUR,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	VIDE,			VIDE,	SPAWN,			VIDE,			VIDE,			VIDE,	VIDE,			MUR,	MUR,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	ONEWAY_HAUT,	VIDE,				ONEWAY_HAUT,	VIDE,	VIDE,	MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	ONEWAY_HAUT,	VIDE,	VIDE,			VIDE,			VIDE,			VIDE,	VIDE,			MUR,	VIDE,				VIDE,			VIDE,			VIDE,			VIDE,				VIDE,	VIDE,	VIDE,			VIDE,				VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	MUR,	MUR},

		{MUR,	MUR,	VIDE,	VIDE,			BLOC,	VIDE,			VIDE,			VIDE,			PIQUE,	PIQUE,			MUR,	BOUTEILLE_VIVANTE,	VIDE,			VIDE,			VIDE,			BOUTEILLE_COULEUR1,	VIDE,	SWITCH,	VIDE,			BOUTEILLE_COULEUR2,	VIDE,			VIDE,	VIDE,	VIDE,	ROCHER,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	MUR,	MUR},
		
		{MUR,	MUR,	MUR,	MUR,			MUR,	MUR,			MUR,			MUR,			MUR,	MUR,			MUR,	MUR,				MUR,			MUR,			MUR,			MUR,				MUR,	MUR,	MUR,			MUR,				MUR,			MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR},

		{MUR,	MUR,	MUR,	MUR,			MUR,	MUR,			MUR,			MUR,			MUR,	MUR,			MUR,	MUR,				MUR,			MUR,			MUR,			MUR,				MUR,	MUR,	MUR,			MUR,				MUR,			MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR},

	}));


	MJ.addMap(Map(1500, {

		{MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,			MUR,	MUR,	MUR,	MUR,	MUR,		MUR,		MUR,		MUR,	MUR,	MUR,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		VIDE,		VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		VIDE,		VIDE,		VIDE,	GOAL,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		VIDE,		VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		ONEWAY_BAS,	VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	ONEWAY_BAS,	VIDE,		ONEWAY_BAS,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		VIDE,		VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	ROCHER,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		ONEWAY_BAS,	VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	ONEWAY_BAS,	VIDE,		ONEWAY_BAS,	VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		VIDE,		VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		VIDE,		VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	SPAWN,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,			VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		VIDE,		VIDE,		VIDE,	VIDE,	VIDE,		MUR},

		{MUR,	VIDE,	VIDE,	VIDE,	BLOC,	BLOC,	BLOC_COULEUR1,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,		SWITCH,		VIDE,		VIDE,	VIDE,	BOUTEILLE,	MUR},

		{MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,			MUR,	MUR,	MUR,	MUR,	MUR,		MUR,		MUR,		MUR,	MUR,	MUR,		MUR},

	}));
	

	MJ.addMap(Map(500,{

		{MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR},


		{MUR,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	VIDE,	MUR},


		{MUR,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	GOAL,	GOAL,	VIDE,	GOAL,	GOAL,	GOAL,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	MUR},


		{MUR,	VIDE,	VIDE,	VIDE,	GOAL,	GOAL,	VIDE,	GOAL,	GOAL,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	VIDE,	MUR},


		{MUR,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	GOAL,	VIDE,	VIDE,	GOAL,	GOAL,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	MUR},


		{MUR,	SPAWN,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	VIDE,	MUR},


		{MUR,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	VIDE,	GOAL,	VIDE,	GOAL,	GOAL,	GOAL,	VIDE,	GOAL,	VIDE,	GOAL,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	GOAL,	VIDE,	VIDE,	MUR},


		{MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR,	MUR},

	}));


	MJ.addMap(Map{ 404, {
		{ SPAWN,	VIDE},

		{ VIDE,		VIDE},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL},

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ GOAL,		GOAL },

		{ PIQUE,	PIQUE },

		{ GOAL,		GOAL },

	} });


	MJ.run();
}