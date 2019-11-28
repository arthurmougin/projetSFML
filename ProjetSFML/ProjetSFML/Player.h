#pragma once
#include "MobileEntity.h"
class Scene;

class Player:public MobileEntity
{
protected:
	bool bringSomething;
	GameObject* bringElement;
	GameColor bringColor = NOCOLOR;
	FloatRect interactionBox = FloatRect(0, 0, 160, 160);

public:
	/* CONSTRUCTEURS */
	Player();//Constructeur standard
	Player(Vector2f, Texture, IntRect);//Constructeur utilisé dans la génération de la scene 

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void update(Scene *);
	FloatRect getInteractionBox();

	/* GETER SETER */
	void moveTo(Direction);
	bool getBringSomething();
	void setBringSomething(bool);
	GameObject* getBringElement();
	void setBringElement(GameObject*);
	GameColor getBringColor();
	void setBringColor(GameColor);
	void placeBringElement();
	bool goingLeft();
};

