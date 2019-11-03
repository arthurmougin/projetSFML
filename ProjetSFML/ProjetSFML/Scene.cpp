#include "Scene.h"

Scene::Scene()
{
	score = 0;
	playerContainer.Name = "player1";
	playerContainer.type = PLAYER;
	playerContainer.player = Player();
}

Scene::Scene(int s, vector<vector<int>> m)
{
	score = s;
	playerContainer.Name = "player1";
	playerContainer.type = PLAYER;
	playerContainer.player = Player();
	generate(m);
}

Scene::Scene(int s, vector<ElementContainer> v, Vector2f sp, ElementContainer p)
{
	score = s;
	gameObjects = v;
	spawnPoint = sp;
	playerContainer = p;
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
	playerContainer.player.draw(e);
	for (int i = 0; i < gameObjects.size(); i++)
	{
		
	}
	/**/
}

bool Scene::testCollide(ElementContainer &e , vector<ElementContainer>& es, Direction D)
{
	FloatRect collisionBox;
	bool TraverseBlock, TraverseMur, MarcheSurBlock, hauteur;
	switch (e.type)
	{
		/**
	case ROCHER:
		break;
		/**/
	case BLOC:
		return false; // Le bloc n'a aucune collision avec l'environment
		break;
		/**
	case BLOC_VIVANT:
		break;
	case ANIMAL:
		break;/**/
	case PLAYER:
		collisionBox = e.player.getFantome().getGlobalBounds();
		TraverseBlock = e.player.getTraverseBlock();
		TraverseMur = e.player.getTraverseMur();
		MarcheSurBlock = e.player.getMarcheSurBlock();
		hauteur = e.player.getHauteur();
		break;
	default:
		cout << "mauvais collisionneur" << endl;
		break;
	}


	for (int i = 0; i < es.size(); i++)
	{
		switch (es.at(i).type)
		{
		case MUR:
			//si l'élément ne traverse pas les murs et qu'il y a une collision
			if (!TraverseMur && collisionBox.intersects(es.at(i).mur.getGlobalBounds()))
				return true;
			break;
		case ONEWAY:
			//si la direction de collision est celle bloquée par le OneWay et qu'il y a une collision
			if (D == es.at(i).oneway.getBlockDirection() && collisionBox.intersects(es.at(i).oneway.getGlobalBounds()))
				return true;
			break;
			/*
		case PIQUE:
			break;
		case SWITCH:
			break;
		case GOAL:
			break;
		case ROCHER:
			break;
		case BOUTEILLE:
			break;
		case BOUTEILLE_VIVANTE:
			break;
		case BLOC:
			break;
		case BLOC_VIVANT:
			break;
		case ANIMAL:
			break;/**/
		default:
			break;
		}
	}

	// si l'element pour lequel on teste les collisions n'est pas un joueur, alors on doit tester cette option
	if (e.type != PLAYER) {
		collisionBox.intersects(playerContainer.player.getGlobalBounds());
	}
	return false;
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
	return playerContainer;
}

void Scene::setPlayer(ElementContainer p)
{
	playerContainer = p;
}

Vector2f Scene::getSpawnPoint()
{
	return spawnPoint;
}

void Scene::setSpawnPoint(Vector2f s)
{
	spawnPoint = s;
}