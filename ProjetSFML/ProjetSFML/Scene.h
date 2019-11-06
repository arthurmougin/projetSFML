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


class Scene
{
protected:
	int score;
	vector <GameObject *> gameObjects;
	Player player;
	Vector2f spawnPoint;
public:
	Scene();
	Scene(int, vector <vector <int>>);
	Scene(int, vector <GameObject*>, Vector2f , Player);

	void generate(vector <vector <int>>);
	void draw(RenderWindow*);
	bool testCollide(GameObject*, Direction);
	void update();

	int getScore();
	void setScore(int);
	vector <GameObject*> getGameObjects();
	void setGameObjects(vector <GameObject*>);
	Player getPlayer();
	void setPlayer(Player);
	Vector2f getSpawnPoint();
	void setSpawnPoint(Vector2f);
};

