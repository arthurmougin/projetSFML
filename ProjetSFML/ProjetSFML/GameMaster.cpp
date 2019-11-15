#include "GameMaster.h"

GameMaster::GameMaster():RenderWindow(VideoMode(1200, 1000), "Sutte Hakkun by Arthur Mougin")
{
	selectedMapIndex = 0;
	framerate = 60;
	MainClock.restart();
}

void GameMaster::run()
{
	cout << "Run" << endl;
	Map mainMap = maps.at(selectedMapIndex);

	while (isOpen()) {

		if (MainClock.getElapsedTime().asSeconds() > (1 / 60))
		{
			//si la map est en cours de jeu
			if (mainMap.getIsPlaying()) {
				//mainMap.update();
				mainMap.draw(*this);
			}
			else {
				//si la map viens d'etre finis, on la réinitialise et on passe à la map suivante
				cout << "switch map" << endl;
				mainMap.setIsPlaying(true);
				selectedMapIndex = (selectedMapIndex + 1) % maps.size();

				mainMap = maps.at(selectedMapIndex);
			}

			MainClock.restart();
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
