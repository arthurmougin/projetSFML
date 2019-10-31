#include "Scene.h"

Scene::Scene()
{
	score = 0;
	player.Name = "player1";
	player.type = "player";
	player.player = Player();
}

Scene::Scene(int s, vector<vector<int>> m)
{
	score = s;
	player.Name = "player1";
	player.type = "player";
	player.player = Player();
	generate(m);
}

Scene::Scene(int s, vector<ElementContainer> v, Vector2f sp, ElementContainer p)
{
	score = s;
	gameObjects = v;
	spawnPoint = sp;
	player = p;
}

void Scene::generate(vector<vector<int>>myMatrice)
{
	/*
	enum ElementTypes {VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, ONEWAY_DROITE,
	PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL,
	ANIMAL_COULEUR1, ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN };
	*/
	for (int y = 0; y < myMatrice.size(); y++) {
		vector <int> myLine = myMatrice.at(y);
		for (int x = 0; x < myLine.size(); x++) {

			switch (myLine.at(x)) {
			case VIDE:
				break;
			case MUR:
				cout << "wall at " << x << " x " << y << endl;
			default:
				cout << "l'index " << myLine.at(x) << " n'est pas connu" << endl;
			}

		}
	}


}

void Scene::draw(RenderWindow &e)
{
	cout << "scene drawn" << endl;
	/**
	player.player.draw(e);
	for (int i = 0; i < gameObjects.size(); i++)
	{
		
	}
	/**/
}

void Scene::update()
{
	cout << "scene updated" << endl;

}

int Scene::getScore()
{
	return score;
}

void Scene::setScore(int s)
{
	score = s;
}

vector<ElementContainer> Scene::getGameObjects()
{
	return gameObjects;
}

void Scene::setGameObjects(vector<ElementContainer> g)
{
	gameObjects = g;
}

ElementContainer Scene::getPlayer()
{
	return player;
}

void Scene::setPlayer(ElementContainer p)
{
	player = p;
}

Vector2f Scene::getSpawnPoint()
{
	return spawnPoint;
}

void Scene::setSpawnPoint(Vector2f s)
{
	spawnPoint = s;
}