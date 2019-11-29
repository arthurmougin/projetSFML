#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


int MAX_ITEMS = 5;

class MainMenu
{
protected:
	int SelectedItemIndex;
	vector <Text*> elements;

public:
	MainMenu(float, float);
	void Update(RenderWindow& GM);
	void draw(RenderWindow& GM);
};

