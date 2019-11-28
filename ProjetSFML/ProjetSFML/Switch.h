#pragma once
#include "GameEntity.h"

//On a besoin de d�clarer la classe en amont pour que Switch puisse la manipuler
class Scene;



class Switch:public GameEntity//Element interactif changeant la couleur des bouteilles
{
public:
	/* CONSTRUCTEURS */
	Switch();//Constructeur standard 
	Switch(Vector2f, Texture, IntRect);//Constructeur utilis� dans la g�n�ration de la scene

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void interact(Scene *);//changement des couleurs quand le player ou un animal interagie avec le switch
};

