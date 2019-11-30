#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MainMenu.h"
using namespace std;
using namespace sf;


class GameMaster:public RenderWindow //Classe du jeu
{
protected:
	vector <Map> maps; //Stock de cartes
	int selectedMapIndex; //index de la carte en cours
	Font *font; //police stockée globalement
	double framerate; //fréquence de jeu
	Clock MainClock; //Horloge pour définir la fréquence de jeu

public:
	/* CONSTRUCTEURS */
	GameMaster();

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void run();

	/* GETER SETER */
	vector <Map> getMaps();
	void setMaps(vector <Map>);
	void addMap(Map);
	void setSelectedMapIndex(int);
	int getSelectedMapIndex();
	Font* getFont();
	void setFont(Font*);
};

