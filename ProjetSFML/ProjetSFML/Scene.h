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
	vector <Mur*> murs;
	vector <OneWay*> oneWays;
	vector <spike*> spikes;
	vector <Bouteille*> bouteilles;
	vector <Switch*> switches;
	Player *player;
	Vector2f spawnPoint;


public:
	Scene();
	Scene(int, vector <vector <enum ElementTypes>>);
	Scene(int, vector <GameObject*>, Vector2f , Player);
	Scene(Scene*);

	void generate(vector <vector <enum ElementTypes>>);
	void draw(RenderWindow&);
	bool testCollide(GameObject*, Direction);
	int update(RenderWindow&);

	int getScore();
	void setScore(int);
	Text getScoreString();
	void setScoreString(Text);
	vector <GameObject*> getGameObjects();
	void setGameObjects(vector <GameObject*>);
	Player getPlayer();
	void setPlayer(Player);
	Vector2f getSpawnPoint();
	void setSpawnPoint(Vector2f);
	vector <Bouteille*> getBouteilles();
	void setBouteilles(vector <Bouteille*>);
	bool walkOn(GameObject*, vector <GameObject*>);
};

