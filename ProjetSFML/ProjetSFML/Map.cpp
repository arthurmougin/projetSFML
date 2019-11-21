#include "Map.h"

Map::Map()
{
	initialScore = 1000;
	highScore = 0;
	gravity = 9.8;
	matrice = {
		{VIDE}
	};
	sauvegardes.push_back(generate());
	isPlaying = true;
}

Map::Map(vector<vector<enum ElementTypes>> M)
{
	initialScore = 1000;
	highScore = 0;
	gravity = 9.8;
	matrice = M;
	sauvegardes.push_back(generate());
	isPlaying = true;

}

Map::Map(int i, vector<vector<enum ElementTypes>> M)
{
	initialScore = i;
	highScore = 0;
	gravity = 9.8;
	matrice = M;
	sauvegardes.push_back(generate());
	isPlaying = true;

}

Map::Map(int i, double g, vector<vector<enum ElementTypes>> M,  vector<Scene> sv)
{
	initialScore = i;
	highScore = 0;
	gravity = g;
	matrice = M;
	sauvegardes = sv;
	isPlaying = true;

}

void Map::finish()
{
	if (sauvegardes.size() != 0) {
		//on recupere le meilleur score
		highScore = sauvegardes.at(0).getScore();

		//On supprime les sauvegardes et on regénère la scene
		while (sauvegardes.size() != 0)
		{
			sauvegardes.pop_back();
		}
		sauvegardes.push_back(generate());
		isPlaying = false;
	}
	else {
		cout << "Not supposed to Finish" << endl;
	}
}

Scene Map::generate()
{
	Scene retour(initialScore,matrice);
	return retour;
}

void Map::quickSave()
{
	int penalty = 20;

	if (sauvegardes.size() != 0) {
		Scene actuel = sauvegardes.at(0);
		sauvegardes.push_back(Scene(actuel.getScore() - penalty, actuel.getGameObjects(), actuel.getSpawnPoint(), actuel.getPlayer()));
	}
	else {
		cout << "Pas de quickSave sans sauvegardes existantes" << endl;
	}
	
}

void Map::loadSave()
{
	if (sauvegardes.size() > 1) {
		sauvegardes.erase(sauvegardes.begin());
		sauvegardes.shrink_to_fit();
		cout << "sauvegarde size = " << sauvegardes.size();
	}
	else {
		cout << "Pas assez de sauvegardes" << endl;
	}
}

void Map::update(RenderWindow& window)
{

	/*
	enum sceneOutput {RienASignaler = -1,
		QuickSave = -2,
		ReloadPrevious = -3,
		Exit = -4,
		Restart = -5
	};
	*/
	int output;
	output = sauvegardes[0].update(window);
	/**/
	switch (output)
	{
	case sceneOutput::RienASignaler:
		break;
	case sceneOutput::QuickSave:
		cout << "QuickSave (not working)" << endl;
		// ajoute une sauvegarde une 
		// sauvegardes.push_back(Scene(sauvegardes[0]));
		
		break;
	case sceneOutput::ReloadPrevious:
		cout << "ReloadPrevious (not working)" << endl;
		// loadSave();

		break;
	case sceneOutput::Exit:
		cout << "Exit" << endl;
		break;
	case sceneOutput::Restart:
		cout << "Restart" << endl;
		sauvegardes.push_back(generate());
		loadSave();

		break;
	default:
		cout << "score = " << output << endl;
		break;
	}
	
	
}

void Map::draw(RenderWindow&R)
{
	sauvegardes[0].draw(R);
}

int Map::getInitialScore()
{
	return initialScore;
}

void Map::setInitialScore(int i)
{
	initialScore = i;
}

double Map::getGravity()
{
	return gravity;
}

void Map::setGravity(double g)
{
	gravity = g;
}

vector<vector<enum ElementTypes>> Map::getMatrice()
{
	return matrice;
}

void Map::setMatrice(vector<vector<enum ElementTypes>> m)
{
	matrice = m;
}

vector<Scene> Map::getSauvegardes()
{
	return sauvegardes;
}

void Map::setSauvegardes(vector<Scene> s)
{
	sauvegardes = s;
}

bool Map::getIsPlaying()
{
	return isPlaying;
}

void Map::setIsPlaying(bool b)
{
	isPlaying = b;
}

