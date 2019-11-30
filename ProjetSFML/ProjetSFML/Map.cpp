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
	// cout << "sauvegarde size = " << sauvegardes.size() << endl ;
	isPlaying = true;
}

Map::Map(vector<vector<enum ElementTypes>> M)
{
	initialScore = 1000;
	highScore = 0;
	gravity = 9.8;
	matrice = M;
	sauvegardes.push_back(generate());
	// cout << "sauvegarde size = " << sauvegardes.size() << endl ;
	isPlaying = true;

}

Map::Map(int i, vector<vector<enum ElementTypes>> M)
{
	initialScore = i;
	highScore = 0;
	gravity = 9.8;
	matrice = M;
	sauvegardes.push_back(generate());
	// cout << "sauvegarde size = " << sauvegardes.size() << endl ;
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
	cout << "finish" << endl;
	if (sauvegardes.size() != 0) {
		//on recupere le meilleur score
		highScore = sauvegardes.at(0).getScore();

		//On supprime les sauvegardes et on regénère la scene
		while (sauvegardes.size() != 0)
		{
			sauvegardes.pop_back();
		}
		sauvegardes.push_back(generate());
		// cout << "sauvegarde size = " << sauvegardes.size() << endl ;
		isPlaying = false;
	}
	else {
		// cout << "Not supposed to Finish" << endl;
	}
}

Scene Map::generate()
{
	Scene retour(initialScore,matrice);
	return retour;
}

void Map::quickSave()
{
	cout << "quickSave" << endl;

	int penalty = 20;

	//On supprime toutes les sauvegardes pour n'en laisser que la scene en cours
	while (sauvegardes.size() > 1)
	{
		sauvegardes.erase(sauvegardes.begin()+1);
		sauvegardes.shrink_to_fit();
	}

	if (sauvegardes.size() != 0) {
		// cout << "copying" << endl;
		Scene duplique  = Scene(&sauvegardes.at(0));
		duplique.setScore(duplique.getScore() - penalty);
		sauvegardes.push_back(duplique);
		// cout << "sauvegarde size = " << sauvegardes.size() << endl ;
	}
	else {
		cout << "Pas de quickSave sans sauvegardes existantes" << endl;
	}
	
}

void Map::loadSave()
{
	cout << "loadSave" << endl;

	if (sauvegardes.size() > 1) {
		//Transfert du texte
		sauvegardes.at(1).setScoreString(sauvegardes.at(0).getScoreString());
		sauvegardes.erase(sauvegardes.begin());
		sauvegardes.shrink_to_fit();
		
		// cout << "sauvegarde size = " << sauvegardes.size() << endl ;
	}
	else {
		// cout << "Pas assez de sauvegardes" << endl;
	}
}

void Map::update(RenderWindow& window, vector <Event>Evts)
{

	int output;
	output = sauvegardes[0].update(window, Evts);

	if (output > 0) {//You Win
		cout << "score = " << output << endl;
		if (output > highScore) {
			highScore = output;
			cout << "new high score : " << output << endl;
		}
		isPlaying = false;
		return;
	}
	if (output == 0) {//You Died
		cout << "restart" << endl;
		restart();
	}
}

void Map::draw(RenderWindow&R)
{
	sauvegardes[0].draw(R);
}

void Map::restart()
{
	// cout << "restart" << endl;

	//On supprime toutes les sauvegardes pour n'en laisser qu'une
	while (sauvegardes.size() > 1)
	{
		sauvegardes.erase(sauvegardes.begin());
		sauvegardes.shrink_to_fit();
	}
	//On ajoute une sauvegarde vierge
	sauvegardes.push_back(generate());
	// cout << "sauvegarde size = " << sauvegardes.size() << endl ;
	//et on la charge
	loadSave();
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

	if (isPlaying == true)
		restart();
}

