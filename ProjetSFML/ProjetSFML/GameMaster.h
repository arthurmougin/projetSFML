#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"


using namespace std;
using namespace sf;


struct ElementContainer
{
	String type;
	String Name;
	GameObject gameObject;

}; 




class GameMaster
{
private:
	float gravity;
	int maxVie;
	vector <ElementContainer> GameObjects;

public:
	GameMaster();
	void run();

	float getGravity();
	void setGravity(float);
	int getMaxVie();
	void setMaxVie(int);
	vector <ElementContainer> getGameObjects();
	void setGameObjects(vector <ElementContainer>);

};

