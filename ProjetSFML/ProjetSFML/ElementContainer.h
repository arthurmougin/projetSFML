#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/audio.hpp>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

using namespace std;
using namespace sf;

class ElementContainer
{
private:
	String Type;
	String name;
	GameObject gameObject;

public:
	ElementContainer();
	String getType();
	void setType(String);
	String getName();
	void setName(String);


};

