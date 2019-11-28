#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Mur.h"
#include "Player.h"
#include "OneWay.h"
#include "Switch.h"
#include "spike.h"
#include "Bouteille.h"
#include "Rocher.h"
#include "Goal.h"
#include "Block.h"


using namespace std;
using namespace sf;

enum sceneOutput {
	RienASignaler = -1,
	QuickSave = -2,
	ReloadPrevious = -3,
	Exit = -4,
	Restart = -5
};

class Scene
{
protected:
	int score;
	Text ScoreString;
	vector <GameObject *> gameObjects;
	vector <GameObject *> grabbablesETInhalables;
	vector <GameObject *> paintables;
	vector <Mur*> murs;
	vector <OneWay*> oneWays;
	vector <spike*> spikes;
	vector <Bouteille*> bouteilles;
	vector <Switch*> switches;
	vector <Goal*> goals;

	Player *player;
	Vector2f spawnPoint;


public:
	/* CONSTRUCTEURS */
	Scene();//Constructeur standard
	Scene(int, vector <vector <enum ElementTypes>>);
	Scene(int, vector <GameObject*>, Vector2f , Player);
	Scene(Scene*);

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void generate(vector <vector <enum ElementTypes>>);
	void draw(RenderWindow&);
	GameObject* testCollide(GameObject*, Direction);
	int update(RenderWindow&);
	bool walkOn(GameObject*, vector <GameObject*>);

	/* GETER SETER */
	int getScore();
	void setScore(int);
	Text getScoreString();
	void setScoreString(Text);
	vector <GameObject*> getGrabbablesETInhalables();
	void setGrabbablesETInhalables(vector <GameObject*>);
	vector <GameObject*> getGameObjects();
	void setGameObjects(vector <GameObject*>);
	Player getPlayer();
	void setPlayer(Player);
	Vector2f getSpawnPoint();
	void setSpawnPoint(Vector2f);

	vector <Bouteille*> getBouteilles();
	void setBouteilles(vector <Bouteille*>);

	
};

