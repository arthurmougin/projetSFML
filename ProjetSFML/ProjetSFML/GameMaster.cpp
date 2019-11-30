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
	v.zoom(0.30f);
	this->setView(v);

	//Ensemble des actions disponibles dans le menu
	vector <String> MainMenuInputs;
	//Génération des inputs
	for (int i = 0; i < maps.size(); i++)
		MainMenuInputs.push_back("Play Level " + to_string(i + 1));
	MainMenuInputs.push_back("Exit/return (Escape)");

	Event event;
	vector <Event> eventList;//sert pour envoyer les événements aux maps/scenes si ils ne concernent pas le GameMaster
				
	MainMenu menu(this->getSize().x, this->getSize().y, font, MainMenuInputs);//menu principale
	menu.setOpened(true);


	cout << "Run" << endl;
	Map mainMap = maps.at(selectedMapIndex);

	while (isOpen()) {

		
		

		if (float(MainClock.getElapsedTime().asSeconds()) >= 0.016)//1 / 60 = 0.016
		{
			eventList.clear();
			eventList.shrink_to_fit();
			while (this->pollEvent(event)) {
				switch (event.type)
				{
				case Event::Closed:
					this->close();
					break;
				case Event::KeyPressed:

					if (event.key.code == Keyboard::Escape) {
						cout << "Exit" << endl;
						this->close();
					}

					if (menu.getOpened()) {

						if (event.key.code == Keyboard::Down) {
							menu.MoveDown();
						}
						else if (event.key.code == Keyboard::Up) {
							menu.MoveUp();
						}
						else if (event.key.code == Keyboard::Enter) {
							if (menu.getSelectedItemIndex() == 5)
								this->close();
							else {
								selectedMapIndex = menu.getSelectedItemIndex();
								mainMap = maps.at(selectedMapIndex);
								menu.setOpened(false);
							}
						}
					}
					else {
						if (event.key.code == Keyboard::E) {
							menu.setOpened(true);
						}
						else {
							eventList.push_back(event);
						}
					}
					break;
				default:
					eventList.push_back(event);
					break;
				}
			}

			if (menu.getOpened()) {
				menu.drawMe(*this);
			}
			else {
				//cout << float(MainClock.getElapsedTime().asSeconds()) << " " << float(1 / 25)  << endl;
				//si la map est en cours de jeu
				if (mainMap.getIsPlaying()) {
					mainMap.update(*this, eventList);
					mainMap.draw(*this);
				}
				else {
					//si la map viens d'etre finis, on la réinitialise et on passe à la map suivante
					cout << "switch map" << endl;
					mainMap.setIsPlaying(true);

					selectedMapIndex = (selectedMapIndex + 1) % maps.size();

					mainMap = maps.at(selectedMapIndex);
				}
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
