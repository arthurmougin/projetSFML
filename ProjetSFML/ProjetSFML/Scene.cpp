#include "Scene.h"

Scene::Scene()
{
	score = 0;
}

Scene::Scene(int s, vector<vector<enum ElementTypes>> m)
{
	score = s;
	generate(m);
}

Scene::Scene(int s, vector <GameObject*> v, Vector2f sp, Player p)
{
	score = s;
	gameObjects = v;
	spawnPoint = sp;
	player = &p;


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
							MyPosition.x *= x;							
							MyPosition.y *= y;
							
							Mur* GameObjectPtr =  new Mur(MyPosition, nonPlayerTex, MyEntityTextRect);							
							GameObjectPtr->getSprite()->setScale(EntityScale);
							/*gameObjects.push_back(GameObjectPtr);*/
							murs.push_back(GameObjectPtr);
							gameObjects.push_back(GameObjectPtr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
#pragma endregion
					case ONEWAY_HAUT:
						cout << "OneWay Haut at " << x << "x - " << y << "y : "<< endl;
						break;
					case ONEWAY_BAS:
						cout << "OneWay Bas at " << x << "x - " << y << "y : "<< endl;
						break;
					case ONEWAY_GAUCHE:
						cout << "OneWay Gauche at " << x << "x - " << y << "y : " << endl;
						break;
					case ONEWAY_DROITE:
						cout << "OneWay Droite at " << x << "x - " << y << "y : " << endl;
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

							spawnPoint.x = MyPosition.x * x;
							spawnPoint.y = MyPosition.y * y;
							;

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

	e.clear();
	//cout << " player TEXTURE ->  x:" << player->getTexture()->getSize().x << "  y:" << player->getTexture()->getSize().y << endl;
	player->drawMe(e);
	
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->drawMe(e);
	}
	

	//cout << endl;
	e.display();

}

bool Scene::testCollide(GameObject*e , Direction D)
{
	cout << "TestColliding" << endl;
	FloatRect collisionBox;
	bool TraverseBlock, TraverseMur, MarcheSurBlock, hauteur;
	TraverseBlock = TraverseMur = MarcheSurBlock = hauteur = false;

	Player* PlayerPointer;
	PlayerPointer = dynamic_cast<Player*>(e);
	if (PlayerPointer) {
		cout << "This is a player" << endl;
		collisionBox = PlayerPointer->getUpdatedFantome(D).getGlobalBounds();
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


#pragma endregion

#pragma region entity_collision
	Mur* MurPointer;
	OneWay* oneWayPtr;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (!TraverseMur) {
			MurPointer = dynamic_cast<Mur*>(gameObjects.at(i));
			if (MurPointer && collisionBox.intersects(MurPointer->getSprite()->getGlobalBounds())) {
				cout << "Colliding\n";
				return true;
			}
		}

		oneWayPtr = dynamic_cast<OneWay*>(gameObjects.at(i));
		if (oneWayPtr && D == oneWayPtr->getBlockDirection() && collisionBox.intersects(oneWayPtr->getSprite()->getGlobalBounds())) {
			cout << "Colliding\n";

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
	if (PlayerPointer == NULL && collisionBox.intersects(player->getSprite()->getGlobalBounds())) {
		cout << "Colliding\n";

		return true;
	}
	cout << "Not Colliding\n";
#pragma endregion 

	return false;
}

void Scene::update(RenderWindow& GM)
{
	Event event;
	while (GM.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			GM.close();
			break;
		default:
			break;
		}
	}

#pragma region playerMove
	//Input dans les 4 directions
	bool testcollhaut,testcollbas;
	testcollhaut = testCollide(player, Direction::HAUT);
	if (Keyboard::isKeyPressed(Keyboard::Up) && !testcollhaut) {
		cout << "Up" << endl;
		player->moveTo(Direction::HAUT);
	}	
	//si la hauteur du personnage est superieur à 0, on vérifie s'il ne s'est pas cogné la tete
	if (player->getHauteur() != 0 && testcollhaut) {
		player->setAcceleration(Vector2f(0, 0));
		float localY = player->getSprite()->getPosition().y, LocalDelta;
		localY = (int(localY) % 160) + localY - int(localY);
		cout << "localy : " << localY << endl;
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
	else {
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			cout << "Down" << endl;
			player->moveTo(Direction::BAS);
		}
		if (player->getHauteur() == 0) {
			//player->setHauteur(1);
		}
			
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && !testCollide(player, Direction::GAUCHE)) {
		cout << "Left" << endl;
		player->moveTo(Direction::GAUCHE);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && !testCollide(player, Direction::DROITE))
	{
		cout << "Right" << endl;
		player->moveTo(Direction::DROITE);
	}





	player->updatePos(9.8);
#pragma endregion

	cout << endl;
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