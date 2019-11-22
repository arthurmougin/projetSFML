#include "Scene.h"



Scene::Scene()
{
	score = 0;
	ScoreString.setString(to_string(score));
	ScoreString.setCharacterSize(60);
	ScoreString.setStyle(Text::Regular);
	ScoreString.setOutlineThickness(20);

}

Scene::Scene(int s, vector<vector<enum ElementTypes>> m)
{
	cout << "Generation" << endl;
	score = s;
	generate(m);
	ScoreString.setString(to_string(score));
	ScoreString.setCharacterSize(60);
	ScoreString.setStyle(Text::Regular);
	ScoreString.setOutlineThickness(20);

}

Scene::Scene(int s, vector <GameObject*> v, Vector2f sp, Player p)
{
	score = s;
	gameObjects = v;
	spawnPoint = sp;
	player = &p;
	ScoreString.setString(to_string(score));
	ScoreString.setCharacterSize(60);
	ScoreString.setStyle(Text::Regular);
	ScoreString.setOutlineThickness(20);

}

Scene::Scene(Scene*S2)
{
	score = S2->getScore();
	gameObjects = S2->getGameObjects();
	player = &S2->getPlayer();
	spawnPoint = S2->getSpawnPoint();
	ScoreString.setString(to_string(score));
	ScoreString.setCharacterSize(60);
	ScoreString.setStyle(Text::Regular);
	ScoreString.setOutlineThickness(20);

}

void Scene::generate(vector<vector<enum ElementTypes>>myMatrice)
{

	Texture nonPlayerTex;
	Texture PlayerTex;
	if (!nonPlayerTex.loadFromFile("img/NonPlayer.png"))
	{
		cout << "failToLoad nonPlayerTex" << endl;
	}
	
	if (!PlayerTex.loadFromFile("img/Player.png"))
	{
		cout << "failToLoad PlayerTex" << endl;
	}
	else
		cout << PlayerTex.getSize().x << " " << PlayerTex.getSize().y << endl;
	IntRect MyEntityTextRect, MyPlayerTextRect;
	//EntityScale = ratio de proportion des entitées;
	//ArenaScale = Dimension de la case occupée par un élément
	Vector2f EntityScale(20,20), PlayerScale(10, 10),ArenaScale(160,160), MyPosition;

	/*
	enum ElementTypes {VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, ONEWAY_DROITE,
	PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL,
	ANIMAL_COULEUR1, ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN };

	*/
	for (int y = 0; y < myMatrice.size(); y++) {
		vector <enum ElementTypes> myLine = myMatrice.at(y);
		for (int x = 0; x < myLine.size(); x++) {
			if (myLine.at(x) != VIDE) {				
				MyEntityTextRect.width = MyEntityTextRect.height = 8;
				
				MyPosition = ArenaScale;
				MyPosition.x *= x;
				MyPosition.y *= y;
				
				switch (myLine.at(x)) {
					case MUR:
#pragma region MUR
						try {
							//cout << endl <<"wall at " << x << "x - " << y << "y : ";

							// CHOIX DE TEXTURE
							if (y-1 >= 0 && myMatrice[y-1][x] != MUR){

								if (((x + 1) < myLine.size()) && myMatrice[y][x + 1] != MUR) {

									if ((x - 1 >= 0) && (myMatrice[y][x - 1] != MUR)) {
											//cout << "Haut";
											MyEntityTextRect.left = MyEntityTextRect.width * 0;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;
										} else {

											//cout << "Haut Droite";
											MyEntityTextRect.left = MyEntityTextRect.width * 3;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;

									}} else {
										if (x - 1 >= 0 && myMatrice[y][x - 1] != MUR) {

											//cout << "Haut Gauche";
											MyEntityTextRect.left = MyEntityTextRect.width * 1;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;

										} else {

											//cout << "Haut";
											MyEntityTextRect.left = MyEntityTextRect.width * 0;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;

							}}} 
							else if (y + 1 >= myMatrice.size() || myMatrice[y + 1][x] == MUR){

								//cout << "interrieur";
								MyEntityTextRect.left = MyEntityTextRect.width * 2;
								MyEntityTextRect.top = MyEntityTextRect.height * 3;
							}  
							else {
								if ((x + 1 < myLine.size()) && myMatrice[y][x + 1] != MUR) {
									if ((x - 1 >= 0) && myMatrice[y][x - 1] != MUR) {

										//cout << "Bas";
										MyEntityTextRect.left = MyEntityTextRect.width * 0;
										MyEntityTextRect.top = MyEntityTextRect.height * 4;
										MyEntityTextRect.height *= -1;
									} else {

										//cout << "Bas Droite";
										MyEntityTextRect.left = MyEntityTextRect.width * 3;
										MyEntityTextRect.top = MyEntityTextRect.height * 4;
										MyEntityTextRect.height *= -1;

								}} else {
									if (x - 1 >= 0 && myMatrice[y][x - 1] != MUR) {

										//cout << "Bas Gauche";
										MyEntityTextRect.left = MyEntityTextRect.width * 1;
										MyEntityTextRect.top = MyEntityTextRect.height * 4;
										MyEntityTextRect.height *= -1;

									}
									else {

										//cout << "Bas";
										MyEntityTextRect.left = MyEntityTextRect.width * 0;
										MyEntityTextRect.top = MyEntityTextRect.height * 4;
										MyEntityTextRect.height *= -1;
							}}}

							//cout << endl;
							//cout << "Rectangle : x:" << MyEntityTextRect.left << " y:" << MyEntityTextRect.top << " width:" << MyEntityTextRect.width << " height:" << MyEntityTextRect.height << endl;

							//On applique les coordonnées
							
							
							Mur* Murptr =  new Mur(MyPosition, nonPlayerTex, MyEntityTextRect);							
							Murptr->getSprite()->setScale(EntityScale);
							/*gameObjects.push_back(GameObjectPtr);*/
							murs.push_back(Murptr);
							gameObjects.push_back(Murptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
#pragma endregion
					case ONEWAY:
						try {
							cout << "OneWay (defaut  = Haut) at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::BAS, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ONEWAY_HAUT:
						try {
							cout << "OneWay Haut at " << x << "x - " << y << "y : "<< endl;
						
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::BAS, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ONEWAY_BAS:
						try {
							cout << "OneWay Bas at " << x << "x - " << y << "y : "<< endl;

							MyEntityTextRect.top = 3 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							MyEntityTextRect.height = -MyEntityTextRect.height;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::HAUT, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ONEWAY_GAUCHE:
						try {
							cout << "OneWay Gauche at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							MyEntityTextRect.width = -MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::DROITE, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ONEWAY_DROITE:
						try {
							cout << "OneWay Droite at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 1 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::GAUCHE, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case PIQUE:
						try {
							cout << "spike at " << x << "x - " << y << "y : " << endl;
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							spike* spptr = new spike( MyPosition, nonPlayerTex, MyEntityTextRect);
							spptr->getSprite()->setScale(EntityScale);
							spikes.push_back(spptr);
							gameObjects.push_back(spptr);

						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case SPAWN:
						try {
							cout << endl << "SpawnPoint at " << x << "x - " << y << "y : ";
							if (x + 1 < myLine.size() && myLine.at(x + 1) == VIDE && y + 1 < myMatrice.size() && myMatrice.at(x).at(y + 1) == VIDE && myMatrice.at(x + 1).at(y + 1) == VIDE) {
								cout << "VALIDE" << endl;
							}
							else {
								cout << "INVALIDE" << endl;
							}
							MyPlayerTextRect.width = MyPlayerTextRect.height = 32;
							MyPlayerTextRect.left = MyPlayerTextRect.width * 0;
							MyPlayerTextRect.top = MyPlayerTextRect.height * 0;

							cout << "Rectangle : x:" << MyPlayerTextRect.left << " y:" << MyPlayerTextRect.top << " width:" << MyPlayerTextRect.width << " height:" << MyPlayerTextRect.height << endl;

							spawnPoint.x = MyPosition.x;
							spawnPoint.y = MyPosition.y;

							/**
							player.setTexture(PlayerTex);
							player.setTextureRect(MyPlayerTextRect);
							player.getSprite()->setPosition(spawnPoint);/**/

							Player* pptr = new Player(spawnPoint, PlayerTex, MyPlayerTextRect);
							pptr->getSprite()->setScale(PlayerScale);
							player = pptr;
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					default:
						cout << "l'index " << myLine.at(x) << " n'est pas connu" << endl;
				}
			}
		}
	}
}

void Scene::draw(RenderWindow&e)
{
	View v = e.getView();
	FloatRect centerBox = player->getSprite()->getGlobalBounds();
	Vector2f centre;
	centre.y = centerBox.top + (centerBox.height / 2);
	centre.x = centerBox.left + (centerBox.width / 2);
	v.setCenter(centre);
	e.setView(v);
	centre.x -= 550;
	centre.y -= 450;

	e.clear();
	//cout << " player TEXTURE ->  x:" << player->getTexture()->getSize().x << "  y:" << player->getTexture()->getSize().y << endl;
	player->drawMe(e);
	
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->drawMe(e);
	}
	
	ScoreString.setPosition(centre);
	e.draw(ScoreString);

	e.display();

}

bool Scene::testCollide(GameObject*e , Direction D)
{
	FloatRect collisionBox,ActualBox;
	bool TraverseBlock, TraverseMur, MarcheSurBlock, hauteur;
	TraverseBlock = TraverseMur = MarcheSurBlock = hauteur = false;

	Player* PlayerPointer;
	PlayerPointer = dynamic_cast<Player*>(e);
	if (PlayerPointer) {
		collisionBox = PlayerPointer->getUpdatedFantome(D).getGlobalBounds();
		ActualBox = PlayerPointer->getSprite()->getGlobalBounds();
		TraverseBlock = PlayerPointer->getTraverseBlock();
		TraverseMur = PlayerPointer->getTraverseMur();
		MarcheSurBlock = PlayerPointer->getMarcheSurBlock();
		hauteur = PlayerPointer->getHauteur();
	}
	// A CODER : ROCHER, BLOC, BLOC_VIVANT, ANIMAL
	else {
		cout << "Mauvais collisionneur " << endl;
	}

#pragma region boundery_collision
	/* TODO */

#pragma endregion

#pragma region entity_collision
	Mur* MurPointer;
	OneWay* oneWayPtr;
	spike* spikePtr;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (!TraverseMur) {
			MurPointer = dynamic_cast<Mur*>(gameObjects.at(i));
			if (MurPointer) {
				if (collisionBox.intersects(MurPointer->getSprite()->getGlobalBounds())) {
					//cout << "Colliding\n";
					return true;
				}
				continue;
			}
			
		}

		oneWayPtr = dynamic_cast<OneWay*>(gameObjects.at(i));
		if(oneWayPtr)
		{ 
			/*if (D == Direction::DROITE)
				cout << "DROITE : \n";
			if (D == Direction::HAUT)
				cout << "HAUT : \n";
			if (D == Direction::BAS)
				cout << "BAS : \n";
			if (D == Direction::GAUCHE)
				cout << "GAUCHE : \n";
			cout << "sprite Collide = " << (ActualBox.intersects(oneWayPtr->getSprite()->getGlobalBounds()));
			cout << "fantome Collide = " << collisionBox.intersects(oneWayPtr->getSprite()->getGlobalBounds());
			cout << "blocdirection = direction : " << (D == oneWayPtr->getBlockDirection()) << "true:" << true << endl;*/
			if (!ActualBox.intersects(oneWayPtr->getSprite()->getGlobalBounds()) && D == oneWayPtr->getBlockDirection() && collisionBox.intersects(oneWayPtr->getSprite()->getGlobalBounds())) {
				/*
				Conditions : 
					1 = C'est un OneWay
					2 = l'entité n'est pas actuellement dans la zone de colision
					3 = la direction est la bonne
					4 = le fantome est dans la zone de colision
			
				*/
				cout << "Colliding\n";

				return true;
			}
			
			continue;
		}

		spikePtr = dynamic_cast<spike*>(gameObjects.at(i));
		if (spikePtr) {
			if (PlayerPointer && ActualBox.intersects(spikePtr->getSprite()->getGlobalBounds())) {
				// Si c'est un joueur et qu'il touche actuellement un spike, le jeu est fini
				score = 0;
			}
			continue;
		}
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
	if (PlayerPointer == NULL && collisionBox.intersects(player->getSprite()->getGlobalBounds())) {
		//cout << "Colliding\n";

		return true;
	}
	//cout << "Not Colliding\n";
#pragma endregion 

	return false;
}

int Scene::update(RenderWindow& GM)
{
	/*
	enum sceneOutput {RienASignaler = -1,
		QuickSave = -2,
		ReloadPrevious = -3,
		Exit = -4,
		Restart = -5
	};
	0 -> +  = score
	*/
	int retour = sceneOutput::RienASignaler;
	Event event;
	while (GM.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			GM.close();
			break;
		case Event::KeyPressed:
			/* Format d'inputs
			Left = arrow left
			right = arrow right
			discard = arraw down
			jump = arrow up

			inhale/exhale = crtl right

			Select = s ou num1
			Lock = L ou num4
			cancel = N ou num3
			confirm = O ou num6
			reload = R ou num5
			Quicksave = Q ou num2
			Exit = E ou Echape
			Restart = T ou num8
			
			*/
			if (event.key.code == Keyboard::Down) {
				cout << "discard" << endl;
			}
			if (event.key.code == Keyboard::RControl) {
				cout << "Inhale/Hexale" << endl;
			}
			if (event.key.code == Keyboard::S || event.key.code == Keyboard::Numpad1) {
				cout << "Select" << endl;
			}
			if (event.key.code == Keyboard::L || event.key.code == Keyboard::Numpad4) {
				cout << "Lock" << endl;
			}
			if (event.key.code == Keyboard::N || event.key.code == Keyboard::Numpad3) {
				cout << "cancel" << endl;
			}
			if (event.key.code == Keyboard::O || event.key.code == Keyboard::Numpad6) {
				cout << "confirm" << endl;
			}
			if (event.key.code == Keyboard::R || event.key.code == Keyboard::Numpad5) {
				cout << "Reload" << endl;
				retour = sceneOutput::ReloadPrevious;
				return retour;
			}
			if (event.key.code == Keyboard::Q || event.key.code == Keyboard::Numpad2) {
				cout << "QuickSave" << endl;
				retour = sceneOutput::QuickSave;
				return retour;
			}
			if (event.key.code == Keyboard::T || event.key.code == Keyboard::Numpad8) {
				cout << "Restart" << endl;
				retour = sceneOutput::Restart;
				return retour;
			}
			if (event.key.code == Keyboard::E || event.key.code == Keyboard::Escape) {
				cout << "Exit" << endl;
				GM.close();
			}
			break;
		default:
			break;
		}
	}

#pragma region playerMove
	//cout << endl;
	/*
	setup original :
		--
			if keyboard Haut && !TestCollide Haut 
				moveto Up

			if keyboard Bas && !TestCollide Bas 
				moveto Down

			if playerhauteur!=0 &&é && TestCollide Haut
				Kill velocity

			if playerhauteur!=0 && TestCollide Bas
				Faire attérir le personnage

			if playerhauteur==0 && !TestCollide Bas
				Faire tomber le personnage
		--
		avantages = propreté
		defaut = TestCollide est Très gourmand

		La nouvelle architecture peut paraitre bordellique, mais elle a l'avantage de limiter les calls de TestCollide
	
	*/

	//Input dans les 4 directions
	bool testcollhaut,testcollbas;
	testcollhaut = testCollide(player, Direction::HAUT);
	if (player->getHauteur() == 0 && Keyboard::isKeyPressed(Keyboard::Up) && !testcollhaut) {
		//cout << "Up" << endl;
		score -= 3;
		player->moveTo(Direction::HAUT);
	}	
	//si la hauteur du personnage est superieur à 0, on vérifie s'il ne s'est pas cogné la tete
	if (player->getHauteur() != 0 && testcollhaut) {
		player->setAcceleration(Vector2f(0, 0));
		float localY = player->getSprite()->getPosition().y, LocalDelta;
		localY = (int(localY) % 160) + localY - int(localY);
		//cout << "localy : " << localY << endl;
		if (localY < 80) {
			localY = -localY;
		}
		else {
			localY = 160 - localY;
		}
		player->getSprite()->move(Vector2f(0, localY));
	}
	testcollbas = testCollide(player, Direction::BAS);

	if (testcollbas) {
		if (player->getHauteur() != 0) {
			player->setHauteur(0);
			float localY = player->getSprite()->getPosition().y,LocalDelta;
			localY = (int(localY) % 160)+ localY- int(localY);
			cout << "localy : " << localY << endl;
			if (localY < 80) {
				localY = -localY;
			}
			else {
				localY = 160 - localY;
			}
			player->getSprite()->move(Vector2f(0, localY));
		}
	}
	else if (player->getHauteur() == 0) {
		player->setHauteur(1);
		
		//if(player->getSprite()->getPosition().x)
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && !testCollide(player, Direction::GAUCHE)) {
		score -= 1;
		//cout << "Left" << endl;
		player->moveTo(Direction::GAUCHE);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && !testCollide(player, Direction::DROITE))
	{
		score -= 1;
		//cout << "Right" << endl;
		player->moveTo(Direction::DROITE);
	}





	player->updatePos(9.8/12);
#pragma endregion

	//cout << endl;
	if (score <= 0)
		retour = sceneOutput::Restart;

	cout << to_string(score) << endl;
	ScoreString.setString(to_string(score));
	return retour;
}

int Scene::getScore()
{
	return score;
}

void Scene::setScore(int s)
{
	score = s;
}

Text Scene::getScoreString()
{
	return ScoreString;
}

void Scene::setScoreString(Text t)
{
	ScoreString = t;
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
	return *player;
}

void Scene::setPlayer(Player p)
{
	player = &p;
}

Vector2f Scene::getSpawnPoint()
{
	return spawnPoint;
}

void Scene::setSpawnPoint(Vector2f s)
{
	spawnPoint = s;
}

