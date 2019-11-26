#include "Switch.h"
#include "Scene.h"

Switch::Switch():GameEntity()
{
}

Switch::Switch(Vector2f pos, Texture tex, IntRect rect) : GameEntity(false, pos, tex, rect)
{
}

void Switch::interact(Scene* scene)
{
	vector <Bouteille*> bouteilles = scene->getBouteilles();
	GameColor c;
	for (int i = 0; i < bouteilles.size(); i++)
	{
		c = bouteilles.at(i)->getColor();
		switch (c)
		{
		case NOCOLOR:
			c = ROUGE;
			break;
		case ROUGE:
			c = BLEU;
			break;
		case BLEU:
			c = JAUNE;
			break;
		case JAUNE:
			c = ROUGE;
			break;
		default:
			c = ROUGE;
			break;
		}
		bouteilles.at(i)->setColor(c);
	}
	scene->setBouteilles(bouteilles);
}
