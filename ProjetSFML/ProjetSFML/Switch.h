#pragma once
#include "GameEntity.h"

//On a besoin de déclarer la classe en amont pour que Switch puisse la manipuler
class Scene;



class Switch:public GameEntity//Element interactif changeant la couleur des bouteilles
{
public:
	/* CONSTRUCTEURS */
	Switch();//Constructeur standard 
	Switch(Vector2f, Texture, IntRect);//Constructeur utilisé dans la génération de la scene

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void interact(Scene *);//changement des couleurs quand le player ou un animal interagie avec le switch
};

