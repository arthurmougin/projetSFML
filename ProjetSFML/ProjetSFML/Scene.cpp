#include "Scene.h"

Scene::Scene()
{
	score = 0;
}

Scene::Scene(int s, vector<vector<int>> m)
{
	score = s;
	generate(m);
}

Scene::Scene(int s, vector <GameObject*> v, Vector2f sp, Player p)
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
				break;
			case ONEWAY_HAUT:
				cout << "OneWay Haut at " << x << " x " << y << endl;
				break;
			case ONEWAY_BAS:
				cout << "OneWay Bas at " << x << " x " << y << endl;
				break;
			case ONEWAY_GAUCHE:
				cout << "OneWay Gauche at " << x << " x " << y << endl;
				break;
			case ONEWAY_DROITE:
				cout << "OneWay Droite at " << x << " x " << y << endl;
				break;
			default:
				cout << "l'index " << myLine.at(x) << " n'est pas connu" << endl;
			}

		}
	}


}

void Scene::draw(RenderWindow*e)
{
	cout << "scene drawn" << endl;
	/**
	playerContainer.player.draw(e);
	for (int i = 0; i < gameObjects.size(); i++)
	{

	}
	/**/
}


bool Scene::testCollide(GameObject*e , Direction D)
{
	FloatRect collisionBox;
	bool TraverseBlock, TraverseMur, MarcheSurBlock, hauteur;
	Player* PlayerPointer;
	
	PlayerPointer = dynamic_cast<Player*>(e);
	if (PlayerPointer) {
		collisionBox = PlayerPointer->getFantome().getGlobalBounds();
		TraverseBlock = PlayerPointer->getTraverseBlock();
		TraverseMur = PlayerPointer->getTraverseMur();
		MarcheSurBlock = PlayerPointer->getMarcheSurBlock();
		hauteur = PlayerPointer->getHauteur();
	}
	// A CODER : ROCHER, BLOC, BLOC_VIVANT, ANIMAL
	else {
		cout << "Mauvais collisionneur " << endl;
	}



	Mur* MurPointer;
	OneWay* oneWayPtr;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (!TraverseMur) {
			MurPointer = dynamic_cast<Mur*>(gameObjects.at(i));
			if (MurPointer && collisionBox.intersects(MurPointer->getGlobalBounds())) {
				return true;
			}
		}

		oneWayPtr = dynamic_cast<OneWay*>(gameObjects.at(i));
		if (oneWayPtr && D == oneWayPtr->getBlockDirection() && collisionBox.intersects(oneWayPtr->getGlobalBounds())) {
			return true;
		}


		/*
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
			break;/*
		default:
			break;
		}
		*/
	}

	// si l'element pour lequel on teste les collisions n'est pas un joueur, alors on doit tester cette option
	if (PlayerPointer == NULL && collisionBox.intersects(player.getGlobalBounds())) {
		return true;
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

vector <GameObject*> Scene::getGameObjects()
{
	return gameObjects;
}

void Scene::setGameObjects(vector <GameObject*> g)
{
	gameObjects = g;
}

Player Scene::getPlayer()
{
	return player;
}

void Scene::setPlayer(Player p)
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