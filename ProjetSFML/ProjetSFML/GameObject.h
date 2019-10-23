#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameObject : public Sprite
{
public:
	GameObject();
	virtual void draw()=0;
	virtual void update()=0;
};

