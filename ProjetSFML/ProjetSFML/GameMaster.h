#pragma once
#include "Map.h"

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

