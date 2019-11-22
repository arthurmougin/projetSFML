#include "GameMaster.h"

GameMaster::GameMaster():RenderWindow(VideoMode(1200, 1000), "Sutte Hakkun by Arthur Mougin")
{
	selectedMapIndex = 0;
	framerate = 60;
	MainClock.restart();
}

void GameMaster::run()
{
	View v (FloatRect(0, 0, 4800, 4000));
	v.zoom(0.25f);
	this->setView(v);
	cout << "Run" << endl;
	Map mainMap = maps.at(selectedMapIndex);

	while (isOpen()) {

		if (float(MainClock.getElapsedTime().asSeconds()) >= 0.016)//1 / 60 = 0.016
		{
			//cout << float(MainClock.getElapsedTime().asSeconds()) << " " << float(1 / 25)  << endl;
			//si la map est en cours de jeu
			if (mainMap.getIsPlaying()) {
				mainMap.update(*this);
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
	vector <Scene> saves = m.getSauvegardes();
	Text t;
	for (int i = 0; i < saves.size(); i++)
	{
		t = saves.at(i).getScoreString();
		t.setFont(*font);
		saves.at(i).setScoreString(t);
	}
	m.setSauvegardes(saves);

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

Font* GameMaster::getFont()
{
	return font;
}

void GameMaster::setFont(Font*f)
{
	font = f;
}
