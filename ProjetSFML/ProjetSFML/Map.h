#pragma once
#include "Scene.h"

class Map
{
protected:
	int initialScore;
	int highScore;
	float gravity; //à diviser par l'ecart de temps
	/*
	enum ElementTypes {VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, ONEWAY_DROITE,
	PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL,
	ANIMAL_COULEUR1, ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN};
	*/
	vector <vector<int>> matrice;
	vector <Scene> sauvegardes;
	bool isPlaying;

public:
	Map();
	Map(vector <vector<int>>);
	Map(int, vector <vector<int>>);
	Map(int, float, vector <vector<int>>, vector <Scene>);

	void finish();
	Scene generate();
	void quickSave();
	void loadSave();
	void update();
	void draw(RenderWindow &);

	int getInitialScore();
	void setInitialScore(int);
	float getGravity();
	void setGravity(float);
	vector <vector<int>> getMatrice();
	void setMatrice(vector <vector<int>>);
	vector <Scene> getSauvegardes();
	void setSauvegardes(vector <Scene>);
	bool getIsPlaying();
	void setIsPlaying(bool);
};

