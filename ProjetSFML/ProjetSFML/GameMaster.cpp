#include "GameMaster.h"

GameMaster::GameMaster():RenderWindow(VideoMode(800, 700), "SFML works!")
{
	selectedMapIndex = 0;
}

void GameMaster::run()
{
	Map mainMap = maps.at(selectedMapIndex);
	
	while (isOpen()) {
		//si la map est en cours de jeu
		if (mainMap.getIsPlaying()) {
			mainMap.update();
			mainMap.draw(window);
		}
		else {
			//si la map viens d'etre finis, on la réinitialise et on passe à la map suivante
			mainMap.setIsPlaying(true);
			selectedMapIndex++;
			mainMap = maps.at(selectedMapIndex);
		}
	}
}

vector<Map> GameMaster::getMaps()
{
	return maps;
}

void GameMaster::setMaps(vector<Map>m)
{
	maps = m;
}

void GameMaster::addMap(Map m)
{
	maps.push_back(m);
}

void GameMaster::setSelectedMapIndex(int i)
{
	if (i >= maps.size() || i < 0)
		i = 0;
	selectedMapIndex = i;
}

int GameMaster::getSelectedMapIndex()
{
	return selectedMapIndex;
}
