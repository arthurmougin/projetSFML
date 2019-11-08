#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Map.h"
using namespace std;
using namespace sf;


class GameMaster:public RenderWindow
{
protected:
	vector <Map> maps;
	int selectedMapIndex;
	RenderWindow window;
	

public:
	GameMaster();
	void run();

	vector <Map> getMaps();
	void setMaps(vector <Map>);
	void addMap(Map);
	void setSelectedMapIndex(int);
	int getSelectedMapIndex();

};

