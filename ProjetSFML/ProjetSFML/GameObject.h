#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>



using namespace std;
using namespace sf;

class GameObject : public Sprite
{
public:
	GameObject();
	void draw(RenderWindow&);
	virtual void update();
};

