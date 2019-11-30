#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class MainMenu//Choisir les maps a jouer
{
protected:
	int SelectedItemIndex = 0;
	vector <Text> elements;
	bool opened = false;

public:
	MainMenu(int, int, Font*);
	MainMenu(int, int,Font*,vector<String>);

	void drawMe(RenderWindow& GM);
	void MoveUp();
	void MoveDown();
	bool getOpened();
	void setOpened(bool);
	int getSelectedItemIndex();

};

