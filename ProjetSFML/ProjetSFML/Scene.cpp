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
	//EntityScale = ratio de proportion des entit�es;
	//ArenaScale = Dimension de la case occup�e par un �l�ment
	Vector2f EntityScale(20,20), PlayerScale(9, 9),ArenaScale(160,160), MyPosition;

	/*
	enum ElementTypes {VIDE, MUR, ONEWAY, ONEWAY_HAUT, ONEWAY_BAS, ONEWAY_GAUCHE, ONEWAY_DROITE,
	PIQUE, SWITCH, GOAL, ROCHER, BOUTEILLE, BOUTEILLE_VIVANTE, BOUTEILLE_COULEUR1, BOUTEILLE_COULEUR2,
	BOUTEILLE_COULEUR3, BLOC, BLOC_VIVANT, BLOC_COULEUR1, BLOC_COULEUR2, BLOC_COULEUR3, ANIMAL,
	ANIMAL_COULEUR1, ANIMAL_COULEUR2, ANIMAL_COULEUR3, PLAYER, SPAWN };

	*/
	for (int y = 0; y < myMatrice.size(); y++) {
		vector <enum ElementTypes> myLine = myMatrice.at(y);
		for (int x = 0; x < myLine.size(); x++) {
			if (myLine.at(x) != ElementTypes::VIDE) {
				MyEntityTextRect.width = MyEntityTextRect.height = 8;
				
				MyPosition = ArenaScale;
				MyPosition.x *= x;
				MyPosition.y *= y;
				
				switch (myLine.at(x)) {
					case ElementTypes::MUR:
						try {
							//cout << endl <<"wall at " << x << "x - " << y << "y : ";

							// CHOIX DE TEXTURE
							if (y-1 >= 0 && myMatrice[y-1][x] != ElementTypes::MUR){

								if (((x + 1) < myLine.size()) && myMatrice[y][x + 1] != ElementTypes::MUR) {

									if ((x - 1 >= 0) && (myMatrice[y][x - 1] != ElementTypes::MUR)) {
											//cout << "Haut";
											MyEntityTextRect.left = MyEntityTextRect.width * 0;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;
										} else {

											//cout << "Haut Droite";
											MyEntityTextRect.left = MyEntityTextRect.width * 3;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;

									}} else {
										if (x - 1 >= 0 && myMatrice[y][x - 1] != ElementTypes::MUR) {

											//cout << "Haut Gauche";
											MyEntityTextRect.left = MyEntityTextRect.width * 1;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;

										} else {

											//cout << "Haut";
											MyEntityTextRect.left = MyEntityTextRect.width * 0;
											MyEntityTextRect.top = MyEntityTextRect.height * 3;

							}}} 
							else if (y + 1 >= myMatrice.size() || myMatrice[y + 1][x] == ElementTypes::MUR){

								//cout << "interrieur";
								MyEntityTextRect.left = MyEntityTextRect.width * 2;
								MyEntityTextRect.top = MyEntityTextRect.height * 3;
							}  
							else {
								if ((x + 1 < myLine.size()) && myMatrice[y][x + 1] != ElementTypes::MUR) {
									if ((x - 1 >= 0) && myMatrice[y][x - 1] != ElementTypes::MUR) {

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
									if (x - 1 >= 0 && myMatrice[y][x - 1] != ElementTypes::MUR) {

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

							//On applique les coordonn�es
							
							
							Mur* Murptr =  new Mur(MyPosition, nonPlayerTex, MyEntityTextRect);							
							Murptr->getSprite()->setScale(EntityScale);
							/*gameObjects.push_back(GameObjectPtr);*/
							murs.push_back(Murptr);
							gameObjects.push_back(Murptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY:
						try {
							cout << "OneWay (defaut  = Haut) at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							/*
							Le sens Bloqu� est l'oppos� du sens affich�
							*/
							OneWay* owptr = new OneWay(Direction::BAS, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_HAUT:
						try {
							cout << "OneWay Haut at " << x << "x - " << y << "y : "<< endl;
						
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							/*
							Le sens Bloqu� est l'oppos� du sens affich�
							*/
							OneWay* owptr = new OneWay(Direction::BAS, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_BAS:
						try {
							cout << "OneWay Bas at " << x << "x - " << y << "y : "<< endl;

							MyEntityTextRect.top = 3 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							MyEntityTextRect.height = -MyEntityTextRect.height;
							/*
							Le sens Bloqu� est l'oppos� du sens affich�
							*/
							OneWay* owptr = new OneWay(Direction::HAUT, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_GAUCHE:
						try {
							cout << "OneWay Gauche at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							MyEntityTextRect.width = -MyEntityTextRect.width;
							/*
							Le sens Bloqu� est l'oppos� du sens affich�
							*/
							OneWay* owptr = new OneWay(Direction::DROITE, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_DROITE:
						try {
							cout << "OneWay Droite at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 1 * MyEntityTextRect.width;
							/*
							Le sens Bloqu� est l'oppos� du sens affich�
							*/
							OneWay* owptr = new OneWay(Direction::GAUCHE, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
							gameObjects.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::PIQUE:
						try {
							cout << "spike at " << x << "x - " << y << "y : " << endl;
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							/*
							Le sens Bloqu� est l'oppos� du sens affich�
							*/
							spike* spptr = new spike(MyPosition, nonPlayerTex, MyEntityTextRect);
							spptr->getSprite()->setScale(EntityScale);
							spikes.push_back(spptr);
							gameObjects.push_back(spptr);

						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::SPAWN:
						try {
							cout << endl << "SpawnPoint at " << x << "x - " << y << "y : ";
							cout << myLine.size() << " " << myMatrice.size() << endl;
							if ((x + 1 < myLine.size()) && (myLine.at(x + 1) == ElementTypes::VIDE) && (y + 1 < myMatrice.size()) && (myMatrice.at(x).at(y + 1) == ElementTypes::VIDE) && (myMatrice.at(x + 1).at(y + 1) == ElementTypes::VIDE)) {
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
					case ElementTypes::BOUTEILLE:
						try {
							cout << endl << "BOUTEILLE at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							gameObjects.push_back(btllptr);			
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BOUTEILLE_VIVANTE:
						try {
							cout << endl << "BOUTEILLE_VIVANTE at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 3 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(false, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							gameObjects.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BOUTEILLE_COULEUR1:
						try {
							cout << endl << "BOUTEILLE_COULEUR1 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, ROUGE, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							gameObjects.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;					
					case ElementTypes::BOUTEILLE_COULEUR2:
						try {
							cout << endl << "BOUTEILLE_COULEUR2 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, BLEU, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							gameObjects.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BOUTEILLE_COULEUR3:
						try {
							cout << endl << "BOUTEILLE_COULEUR3 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, JAUNE, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							gameObjects.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::SWITCH:
						try {
							cout << endl << "SWITCH at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 1 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							Switch* swptr = new Switch(MyPosition, nonPlayerTex, MyEntityTextRect);
							swptr->getSprite()->setScale(EntityScale);
							switches.push_back(swptr);
							gameObjects.push_back(swptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ROCHER:
						try {
							cout << endl << "ROCHER at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 3 * MyEntityTextRect.width;
							Rocher* rchptr = new Rocher(MyPosition, nonPlayerTex, MyEntityTextRect);
							rchptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(rchptr);
							gameObjects.push_back(rchptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::GOAL:
						try {
							//cout << endl << "GOAL at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 1 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Goal* goalptr = new Goal(MyPosition, nonPlayerTex, MyEntityTextRect);

							goalptr->getSprite()->setScale(EntityScale);
							goals.push_back(goalptr);
							gameObjects.push_back(goalptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;



					case ElementTypes::BLOC:
						try {
							cout << endl << "BLOC at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(NOCOLOR,MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
							gameObjects.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_VIVANT:
						try {
							cout << endl << "BLOC_VIVANT at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 3 * MyEntityTextRect.width;
							Block* blptr = new Block(true, NOCOLOR, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
							gameObjects.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_COULEUR1:
						try {
							cout << endl << "BLOC_COULEUR1 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(ROUGE, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
							gameObjects.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_COULEUR2:
						try {
							cout << endl << "BLOC_COULEUR2 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(BLEU, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
							gameObjects.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_COULEUR3:
						try {
							cout << endl << "BLOC_COULEUR3 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(JAUNE, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
							gameObjects.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					default:
						cout << "l'index de la case " << x << "x "<< y << "y n'est pas connu" << endl;
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
	centre.x -= 660;
	centre.y -= 550;

	e.clear();
	

	
	for (int i = 0; i < murs.size(); i++)
	{
		murs[i]->drawMe(e);
	}

	for (int i = 0; i < oneWays.size(); i++)
	{
		oneWays[i]->drawMe(e);
	}

	for (int i = 0; i < spikes.size(); i++)
	{
		spikes[i]->drawMe(e);
	}

	for (int i = 0; i < switches.size(); i++)
	{
		switches[i]->drawMe(e);
	}

	for (int i = 0; i < grabbablesETInhalables.size(); i++)
	{
		grabbablesETInhalables[i]->drawMe(e);
	}

	for (int i = 0; i < goals.size(); i++)
	{
		goals[i]->drawMe(e);
	}

	player->drawMe(e);
	
	ScoreString.setPosition(centre);
	e.draw(ScoreString);

	e.display();

}

GameObject* Scene::testCollide(GameObject*e , Direction D)
{
	FloatRect collisionBox,ActualBox;
	bool TraverseBlock, TraverseMur, MarcheSurBlock, hauteur;
	TraverseBlock = TraverseMur = MarcheSurBlock = hauteur = false;

	Player* PlayerPointer;
	PlayerPointer = dynamic_cast<Player*>(e);
	MobileEntity* MobileEntityptr;
	MobileEntityptr = dynamic_cast<MobileEntity*>(e);
	MobileGameplayElement* MobileGameplayElementPointer = dynamic_cast<MobileGameplayElement*>(e);


	if (PlayerPointer) {
		collisionBox = PlayerPointer->getUpdatedFantome(D).getGlobalBounds();
		ActualBox = PlayerPointer->getSprite()->getGlobalBounds();
		TraverseBlock = PlayerPointer->getTraverseBlock();
		TraverseMur = PlayerPointer->getTraverseMur();
		MarcheSurBlock = PlayerPointer->getMarcheSurBlock();
		hauteur = PlayerPointer->getHauteur();
	}
	else if (MobileEntityptr) {
		collisionBox = MobileEntityptr->getUpdatedFantome(D).getGlobalBounds();
		ActualBox = MobileEntityptr->getSprite()->getGlobalBounds();
		TraverseBlock = MobileEntityptr->getTraverseBlock();
		TraverseMur = MobileEntityptr->getTraverseMur();
		MarcheSurBlock = MobileEntityptr->getMarcheSurBlock();
		hauteur = MobileEntityptr->getHauteur();
	}
	else if (MobileGameplayElementPointer) {
		collisionBox = MobileGameplayElementPointer->getUpdatedFantome(D).getGlobalBounds();
		ActualBox = MobileGameplayElementPointer->getSprite()->getGlobalBounds();
		TraverseBlock = MobileGameplayElementPointer->getTraverseBlock();
		TraverseMur = MobileGameplayElementPointer->getTraverseMur();
		MarcheSurBlock = MobileGameplayElementPointer->getMarcheSurBlock();
		hauteur = MobileGameplayElementPointer->getHauteur();
	}
	// A CODER : ROCHER, BLOC, BLOC_VIVANT, ANIMAL
	else {
		cout << "Mauvais collisionneur " << endl;
	}

#pragma region boundery_collision
	/* TODO */

#pragma endregion

#pragma region entity_collision
	if (!TraverseMur) {
		Mur* MurPtr;
		for (int i = 0; i < murs.size(); i++) {
			MurPtr = murs.at(i);
			if (collisionBox.intersects(MurPtr->getSprite()->getGlobalBounds())) {
				//cout << "Colliding\n";
				return MurPtr;
			}
		}
	}

	OneWay* oneWayPtr;
	for (int i = 0; i < oneWays.size(); i++) {
		oneWayPtr = oneWays.at(i);
		if (!ActualBox.intersects(oneWayPtr->getSprite()->getGlobalBounds()) && D == oneWayPtr->getBlockDirection() && collisionBox.intersects(oneWayPtr->getSprite()->getGlobalBounds())) {
			return oneWayPtr;
		}
	}

	spike* spikePtr;
	for (int i = 0; i < spikes.size(); i++) {
		spikePtr = spikes.at(i);
		if (ActualBox.intersects(spikePtr->getSprite()->getGlobalBounds())) {
			if (PlayerPointer)// Si c'est un joueur et qu'il touche actuellement un spike, le jeu est fini
				score = 0;
			else
				return spikePtr;
		}
	}

	Switch* swtchptr;
	for (int i = 0; i < switches.size(); i++) {
		swtchptr = switches.at(i);
		if (collisionBox.intersects(swtchptr->getSprite()->getGlobalBounds())) {
			return swtchptr;
		}
	}

	MobileGameplayElement* mgeptr;
	FocusableElement* fEptr;
	Block* blptr;
	for (int i = 0; i < grabbablesETInhalables.size(); i++) {
		mgeptr = dynamic_cast<MobileGameplayElement*>(grabbablesETInhalables.at(i));

		if (mgeptr) {//cas des �l�ments h�ritant de MobileGameplayElement
			
			fEptr = mgeptr; //On teste leur heritage en focusable Element pour savoir s'ils sont traversable
			if (!fEptr->getTraversable()) {
				//Si on cherche � tester les collisions d'un MobileGameplayElement
				if (MobileGameplayElementPointer) {
					//si l'�l�ment collider  est identique � l'element test�
					if (mgeptr->getSprite()->getGlobalBounds() == ActualBox) {
						//on passe � l'�l�ment suivant
						continue;
					}
				}

				//Dans le cas d'un Block
				blptr = dynamic_cast<Block*>(mgeptr);
				if (blptr) {
					//Si on ne traverse pas les blocks
					//Ou que l'on marche sur les blocks et que l'on test une collision vers le bas
					if (!TraverseBlock || (D == Direction::BAS && MarcheSurBlock)) {
						if (collisionBox.intersects(blptr->getSprite()->getGlobalBounds())) {
							return blptr;
						}
					}
					continue;
				}
				else if (collisionBox.intersects(mgeptr->getSprite()->getGlobalBounds())) {

					return mgeptr;
				}
			}
		}
		else { // cas oppos� (Bouteilles)
			fEptr = dynamic_cast<FocusableElement*>(grabbablesETInhalables.at(i));
			if (!fEptr->getTraversable()) {
				if (collisionBox.intersects(fEptr->getSprite()->getGlobalBounds())) {
					return fEptr;
				}
			}
		}

		//cas de Bouteille
		

	}

	Goal* goalptr;
	for (int i = 0; i < goals.size(); i++)
	{
		//si on entre en collision avec un objectif, on le supprime du tableau de goals
		goalptr = goals.at(i);
		if (ActualBox.intersects(goalptr->getSprite()->getGlobalBounds())) {

			goals.erase(goals.begin() + i);
			goals.shrink_to_fit();

		}
	}
	/*
	case PIQUE:
		break;
	case SWITCH:
		break;
	case GOAL:
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



	// si l'element pour lequel on teste les collisions n'est pas un joueur, alors on doit tester cette option
	if (PlayerPointer == NULL && collisionBox.intersects(player->getSprite()->getGlobalBounds())) {
		//cout << "Colliding\n";

		return player;
	}
	//cout << "Not Colliding\n";
#pragma endregion 

	return NULL;
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
				vector <GameObject*> goptr;
				for (int i = 0; i < switches.size(); i++)
				{
					goptr.push_back(switches.at(i));
				}
				if (walkOn(player, goptr)) {
					cout << "switchColor" << endl;
					switches.at(0)->interact(this);
				}
				else {
					cout << "discard" << endl;
					if (player->getBringColor() != NOCOLOR) {
						player->setBringColor(NOCOLOR);
					}
				}
				
			}
			if (event.key.code == Keyboard::RControl) {
				cout << "Inhale/Hexale" << endl;
				if (player->getBringSomething()) {
					cout << "hexaling" << endl;

					if(player->getBringColor() == NOCOLOR){
						cout << "entity" << endl;
						grabbablesETInhalables.push_back(player->getBringElement());
						player->setBringElement(NULL);
						/*
							Dans le cas d'un depot d'objet dynamique,
							on le met a jour pour qu'il puisse reprendre conscience de sa position
						*/

						MobileEntity* mEptr = dynamic_cast<MobileEntity*>(grabbablesETInhalables.at( 
							grabbablesETInhalables.size() - 1
						));
						if (mEptr)
							mEptr->update(this);

					}
					else {
						cout << "color" << endl;
						FloatRect interactionBox = player->getInteractionBox();
						for (int i = 0; i < grabbablesETInhalables.size() && player->getBringSomething(); i++)
						{
							if (interactionBox.intersects(grabbablesETInhalables.at(i)->getSprite()->getGlobalBounds())) {
								cout << "found Element Neer Mee" << endl;
								MobileGameplayElement* mpptr = dynamic_cast <MobileGameplayElement*>(grabbablesETInhalables.at(i));
								if (mpptr && mpptr->getColor() == NOCOLOR && mpptr->getPaintable()) {
									cout << "Transfert possible "<< endl;
									mpptr->setColor(player->getBringColor());
									player->setBringColor(NOCOLOR);
								}
								else {
									cout << "Transfert impossible " << endl;
								}
								

							}
						}
					}
				}
				else {
					cout << "Inhaling" << endl;
					FloatRect interactionBox = player->getInteractionBox();

					for (int i = 0; i < grabbablesETInhalables.size() && !player->getBringSomething(); i++)
					{
						if (interactionBox.intersects(grabbablesETInhalables.at(i)->getSprite()->getGlobalBounds())) {
							cout << "found something to inhale" << endl;
							Bouteille* btptr = dynamic_cast <Bouteille* >(grabbablesETInhalables.at(i));
							if (btptr) {
								if (btptr->getInhalable()) {
									cout << "Pick Color" << endl;
									player->setBringColor(btptr->getColor());
								}
								else {
									cout << "bouteille vivante" << endl;
								}
							}
							else {
								Block * blptr = dynamic_cast <Block*>(grabbablesETInhalables.at(i));
								if (blptr && blptr->getVivant()) {
									cout << "block vivant" << endl;
								}
								else {
									MobileGameplayElement* mpptr = dynamic_cast <MobileGameplayElement*>(grabbablesETInhalables.at(i));
									if (mpptr->getColor() != NOCOLOR) {
										cout << "Pick Entity's color" << endl;
										player->setBringColor(mpptr->getColor());
										mpptr->setColor(NOCOLOR);
									}
									else {
										cout << "Pick Entity" << endl;
										player->setBringElement(mpptr);
										grabbablesETInhalables.erase(grabbablesETInhalables.begin() + i);
										grabbablesETInhalables.shrink_to_fit();
									}
								}
							}
						}
					}
				}
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


	player->update(this);

	//Mise a jour de tout les �l�ments dynamiques
	for (int i = 0; i < grabbablesETInhalables.size(); i++)
	{
		//si ils h�ritent de MobileGameplayElement
		MobileGameplayElement* mgeptr = dynamic_cast<MobileGameplayElement*>(grabbablesETInhalables.at(i));
		if (mgeptr) {
			mgeptr->update(this);
			continue;
		}
	}

	if (score <= 0)
		retour = sceneOutput::Restart;

	if (goals.size() == 0)
		retour = score;

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

vector<GameObject*> Scene::getGrabbablesETInhalables()
{
	return grabbablesETInhalables;
}

void Scene::setGrabbablesETInhalables(vector<GameObject*>g)
{
	grabbablesETInhalables = g;
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

vector<Bouteille*> Scene::getBouteilles()
{
	return bouteilles;
}

void Scene::setBouteilles(vector<Bouteille*> b)
{
	bouteilles = b;
}

bool Scene::walkOn(GameObject* mvr, vector<GameObject*> obstcl)
{
	FloatRect box = mvr->getSprite()->getGlobalBounds();
	box.top += 10;// on descend la boite pour detecter une collision avec les objets

	for (int i = 0; i < obstcl.size(); i++)
	{
		//cout << "test walkingOn " << i << endl;
		if (box.intersects(obstcl.at(i)->getSprite()->getGlobalBounds()))
		return true;
	}

	return false;
}

