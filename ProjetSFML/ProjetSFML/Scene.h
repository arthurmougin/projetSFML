#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Mur.h"
#include "Player.h"
#include "MobileEntity.h"

using namespace std;
using namespace sf;



struct ElementContainer
{
	ElementTypes type;
	String Name;
	Mur mur;
	Player player;
};

class Scene
{
protected:
	int score;
	vector <ElementContainer> gameObjects;
	ElementContainer player;
	Vector2f spawnPoint;
public:
	Scene();
	Scene(int, vector <vector <int>>);
	Scene(int, vector <ElementContainer>, Vector2f , ElementContainer);

	void generate(vector <vector <int>>);
	void draw(RenderWindow&);

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

