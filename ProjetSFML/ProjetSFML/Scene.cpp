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
	//cout << "Generation" << endl;
	score = s;
	generate(m);
	ScoreString.setString(to_string(score));
	ScoreString.setCharacterSize(60);
	ScoreString.setStyle(Text::Regular);
	ScoreString.setOutlineThickness(20);

}

Scene::Scene(Scene*S2)
{
	// cout << "Cpy" << endl;
	//setup des valeurs simples a copier
	score = S2->getScore();
	spawnPoint = S2->getSpawnPoint();
	ScoreString.setString(to_string(score));
	ScoreString.setCharacterSize(60);
	ScoreString.setStyle(Text::Regular);
	ScoreString.setOutlineThickness(20);

	//copie des entitées
#pragma region copyEntities

	vector <GameObject*> oldgrabbablesETInhalables = S2->getGrabbablesETInhalables();
	Bouteille* bo;
	Rocher* r;
	Block* bl;
	for (int i = 0; i < oldgrabbablesETInhalables.size(); i++)
	{
		bo = dynamic_cast<Bouteille*>(oldgrabbablesETInhalables.at(i));
		if (bo) {
			
			Vector2f EntityScale = bo->getSprite()->getScale();
			bool inhalab = bo->getInhalable();
			Vector2f MyPosition = bo->getSprite()->getPosition();
			Texture nonPlayerTex = *bo->getTexture();
			IntRect MyEntityTextRect = *bo->getTextureRect();
			Bouteille* btllptr = new Bouteille(inhalab, MyPosition, nonPlayerTex, MyEntityTextRect);
			btllptr->getSprite()->setScale(EntityScale);
			bouteilles.push_back(btllptr);
			grabbablesETInhalables.push_back(btllptr);
			continue;
		}

		r = dynamic_cast<Rocher*>(oldgrabbablesETInhalables.at(i));
		if (r) {
			Vector2f EntityScale = r->getSprite()->getScale();
			Vector2f MyPosition = r->getSprite()->getPosition();
			Texture nonPlayerTex = *r->getTexture();
			IntRect MyEntityTextRect = *r->getTextureRect();
			Rocher* rchptr = new Rocher(MyPosition, nonPlayerTex, MyEntityTextRect);
			rchptr->getSprite()->setScale(EntityScale);
			grabbablesETInhalables.push_back(rchptr);
			continue;
		}

		bl = dynamic_cast<Block*>(oldgrabbablesETInhalables.at(i));
		if (bl) {
			GameColor mycolor = bl->getColor();
			bool vivant = bl->getVivant();
			Vector2f EntityScale = bl->getSprite()->getScale();
			Vector2f MyPosition = bl->getSprite()->getPosition();
			Texture nonPlayerTex = *bl->getTexture();
			IntRect MyEntityTextRect = *bl->getTextureRect();
			Block* blptr = new Block(vivant, mycolor, MyPosition, nonPlayerTex, MyEntityTextRect);
			blptr->getSprite()->setScale(EntityScale);
			grabbablesETInhalables.push_back(blptr);
			continue;
		}

	}

	vector <Goal*> oldGoals = S2->getGoals();
	Goal* g;
	for (int i = 0; i < oldGoals.size(); i++)
	{
		g = dynamic_cast<Goal*>(oldGoals.at(i));
		if (g) {
			Vector2f EntityScale = g->getSprite()->getScale();
			Vector2f MyPosition = g->getSprite()->getPosition();
			Texture nonPlayerTex = *g->getTexture();
			IntRect MyEntityTextRect = *g->getTextureRect();

			Goal* goalptr = new Goal(MyPosition, nonPlayerTex, MyEntityTextRect);
			goalptr->getSprite()->setScale(EntityScale);
			goals.push_back(goalptr);
		}
	}
	
	vector <Switch*> oldSwitches = S2->getSwiches();
	Switch* s;
	for (int i = 0; i < oldSwitches.size(); i++)
	{
		s = dynamic_cast<Switch*>(oldSwitches.at(i));
		if (s) {
			Vector2f EntityScale = s->getSprite()->getScale();
			Vector2f MyPosition = s->getSprite()->getPosition();
			Texture nonPlayerTex = *s->getTexture();
			IntRect MyEntityTextRect = *s->getTextureRect();

			Switch* swptr = new Switch(MyPosition, nonPlayerTex, MyEntityTextRect);
			swptr->getSprite()->setScale(EntityScale);
			switches.push_back(swptr);
		}
	}

	vector <spike*> oldSpikes = S2->getSpikes();
	spike* sp;
	for (int i = 0; i < oldSpikes.size(); i++)
	{
		sp = dynamic_cast<spike*>(oldSpikes.at(i));
		if (sp) {
			Vector2f EntityScale = sp->getSprite()->getScale();
			Vector2f MyPosition = sp->getSprite()->getPosition();
			Texture nonPlayerTex = *sp->getTexture();
			IntRect MyEntityTextRect = *sp->getTextureRect();

			spike* spptr = new spike(MyPosition, nonPlayerTex, MyEntityTextRect);
			spptr->getSprite()->setScale(EntityScale);
			spikes.push_back(spptr);
		}
	}

	vector <OneWay*> oldOneWays = S2->getOneWays();
	OneWay* ow;
	for (int i = 0; i < oldOneWays.size(); i++)
	{
		ow = dynamic_cast<OneWay*>(oldOneWays.at(i));
		if (ow) {
			Vector2f EntityScale = ow->getSprite()->getScale();
			Vector2f MyPosition = ow->getSprite()->getPosition();
			Texture nonPlayerTex = *ow->getTexture();
			IntRect MyEntityTextRect = *ow->getTextureRect();
			Direction dir = ow->getBlockDirection();

			OneWay* owptr = new OneWay(dir, MyPosition, nonPlayerTex, MyEntityTextRect);
			owptr->getSprite()->setScale(EntityScale);
			oneWays.push_back(owptr);
		}
	}

	vector <Mur*> oldmurs = S2->getMurs();
	Mur* m;
	for (int i = 0; i < oldmurs.size(); i++)
	{
		m = dynamic_cast<Mur*>(oldmurs.at(i));
		if (m) {
			Vector2f EntityScale = m->getSprite()->getScale();
			Vector2f MyPosition = m->getSprite()->getPosition();
			Texture nonPlayerTex = *m->getTexture();
			IntRect MyEntityTextRect = *m->getTextureRect();
			Mur* Murptr = new Mur(MyPosition, nonPlayerTex, MyEntityTextRect);
			Murptr->getSprite()->setScale(EntityScale);
			murs.push_back(Murptr);
		}
	}

	Player* p = &S2->getPlayer();
	if (p){
		Vector2f PlayerScale = p->getSprite()->getScale();
		Texture PlayerTex = *p->getTexture();
		IntRect MyPlayerTextRect = *p->getTextureRect();
		Vector2f MyPosition = p->getSprite()->getPosition();
		Player* pptr = new Player(MyPosition, PlayerTex, MyPlayerTextRect);
		pptr->getSprite()->setScale(PlayerScale);
		player = pptr;
	}
#pragma endregion 
}

void Scene::generate(vector<vector<enum ElementTypes>>myMatrice)
{
#pragma region GenerationSetup
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
	IntRect MyEntityTextRect, MyPlayerTextRect;
	//EntityScale = ratio de proportion des entitées;
	//ArenaScale = Dimension de la case occupée par un élément
	Vector2f EntityScale(20,20), PlayerScale(9, 9),ArenaScale(160,160), MyPosition;
#pragma endregion
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

							//On applique les coordonnées
							
							
							Mur* Murptr =  new Mur(MyPosition, nonPlayerTex, MyEntityTextRect);							
							Murptr->getSprite()->setScale(EntityScale);
							murs.push_back(Murptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY:
						try {
							//cout << "OneWay (defaut  = Haut) at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::BAS, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_HAUT:
						try {
							//cout << "OneWay Haut at " << x << "x - " << y << "y : "<< endl;
						
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::BAS, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_BAS:
						try {
							//cout << "OneWay Bas at " << x << "x - " << y << "y : "<< endl;

							MyEntityTextRect.top = 3 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							MyEntityTextRect.height = -MyEntityTextRect.height;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::HAUT, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_GAUCHE:
						try {
							//cout << "OneWay Gauche at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							MyEntityTextRect.width = -MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::DROITE, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ONEWAY_DROITE:
						try {
							//cout << "OneWay Droite at " << x << "x - " << y << "y : " << endl;

							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 1 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							OneWay* owptr = new OneWay(Direction::GAUCHE, MyPosition, nonPlayerTex, MyEntityTextRect);
							owptr->getSprite()->setScale(EntityScale);
							oneWays.push_back(owptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::PIQUE:
						try {
							//cout << "spike at " << x << "x - " << y << "y : " << endl;
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							/*
							Le sens Bloqué est l'opposé du sens affiché
							*/
							spike* spptr = new spike(MyPosition, nonPlayerTex, MyEntityTextRect);
							spptr->getSprite()->setScale(EntityScale);
							spikes.push_back(spptr);

						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::SPAWN:
						try {
							/**
							cout << endl << "SpawnPoint at " << x << "x - " << y << "y : ";
							cout << myLine.size() << " " << myMatrice.size() << endl;
							if ((x + 1 < myLine.size()) && (myLine.at(x + 1) == ElementTypes::VIDE) && (y + 1 < myMatrice.size()) && (myMatrice.at(x).at(y + 1) == ElementTypes::VIDE) && (myMatrice.at(x + 1).at(y + 1) == ElementTypes::VIDE)) {
								cout << "VALIDE" << endl;
							}
							else {
								cout << "INVALIDE" << endl;
							}
							/**/
							MyPlayerTextRect.width = MyPlayerTextRect.height = 32;
							MyPlayerTextRect.left = MyPlayerTextRect.width * 0;
							MyPlayerTextRect.top = MyPlayerTextRect.height * 0;

							//cout << "Rectangle : x:" << MyPlayerTextRect.left << " y:" << MyPlayerTextRect.top << " width:" << MyPlayerTextRect.width << " height:" << MyPlayerTextRect.height << endl;
							
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
							//cout << endl << "BOUTEILLE at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);		
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BOUTEILLE_VIVANTE:
						try {
							//cout << endl << "BOUTEILLE_VIVANTE at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 3 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(false, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BOUTEILLE_COULEUR1:
						try {
							//cout << endl << "BOUTEILLE_COULEUR1 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, ROUGE, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;					
					case ElementTypes::BOUTEILLE_COULEUR2:
						try {
							//cout << endl << "BOUTEILLE_COULEUR2 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, BLEU, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BOUTEILLE_COULEUR3:
						try {
							//cout << endl << "BOUTEILLE_COULEUR3 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 4 * MyEntityTextRect.width;
							Bouteille* btllptr = new Bouteille(true, JAUNE, MyPosition, nonPlayerTex, MyEntityTextRect);
							btllptr->getSprite()->setScale(EntityScale);
							bouteilles.push_back(btllptr);
							grabbablesETInhalables.push_back(btllptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::SWITCH:
						try {
							//cout << endl << "SWITCH at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 1 * MyEntityTextRect.height;
							MyEntityTextRect.left = 0 * MyEntityTextRect.width;
							Switch* swptr = new Switch(MyPosition, nonPlayerTex, MyEntityTextRect);
							swptr->getSprite()->setScale(EntityScale);
							switches.push_back(swptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::ROCHER:
						try {
							//cout << endl << "ROCHER at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 2 * MyEntityTextRect.height;
							MyEntityTextRect.left = 3 * MyEntityTextRect.width;
							Rocher* rchptr = new Rocher(MyPosition, nonPlayerTex, MyEntityTextRect);
							rchptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(rchptr);
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
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC:
						try {
							// cout << endl << "BLOC at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(NOCOLOR,MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_VIVANT:
						try {
							// cout << endl << "BLOC_VIVANT at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 3 * MyEntityTextRect.width;
							Block* blptr = new Block(true, NOCOLOR, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_COULEUR1:
						try {
							// cout << endl << "BLOC_COULEUR1 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(ROUGE, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_COULEUR2:
						try {
							// cout << endl << "BLOC_COULEUR2 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(BLEU, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
						}
						catch (exception & e) { cout << "Exception: " << e.what(); }
						break;
					case ElementTypes::BLOC_COULEUR3:
						try {
							// cout << endl << "BLOC_COULEUR3 at " << x << "x - " << y << "y : ";
							MyEntityTextRect.top = 0 * MyEntityTextRect.height;
							MyEntityTextRect.left = 2 * MyEntityTextRect.width;
							Block* blptr = new Block(JAUNE, MyPosition, nonPlayerTex, MyEntityTextRect);
							blptr->getSprite()->setScale(EntityScale);
							grabbablesETInhalables.push_back(blptr);
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
	Direction OpposeD = Direction::HAUT;
	switch (D)
	{
	case Direction::HAUT:
		OpposeD = Direction::BAS;
		break;
	case Direction::BAS:
		OpposeD = Direction::HAUT;
		break;
	case Direction::GAUCHE:
		OpposeD = Direction::DROITE;
		break;
	case Direction::DROITE:
		OpposeD = Direction::GAUCHE;
		break;
	default:
		break;
	}
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

	//Ajustement des zones de collision
	collisionBox = getInnerBounds(D, collisionBox);
	ActualBox = getInnerBounds(D, ActualBox);



#pragma region entity_collision
	if (!TraverseMur) {
		Mur* MurPtr;
		for (int i = 0; i < murs.size(); i++) {
			MurPtr = murs.at(i);
			if (collisionBox.intersects(getInnerBounds(OpposeD,MurPtr->getSprite()->getGlobalBounds()))) {
				//cout << "Colliding\n";
				return MurPtr;
			}
		}
	}

	OneWay* oneWayPtr;
	for (int i = 0; i < oneWays.size(); i++) {
		oneWayPtr = oneWays.at(i);
		if (!ActualBox.intersects( oneWayPtr->getSprite()->getGlobalBounds()) && D == oneWayPtr->getBlockDirection() && collisionBox.intersects(getInnerBounds(OpposeD, oneWayPtr->getSprite()->getGlobalBounds()))) {
			return oneWayPtr;
		}
	}

	spike* spikePtr;
	for (int i = 0; i < spikes.size(); i++) {
		spikePtr = spikes.at(i);
		if (ActualBox.intersects(spikePtr->getSprite()->getGlobalBounds())) {
			if (PlayerPointer)// Si c'est un joueur et qu'il touche actuellement un spike, le jeu est fini
			{
				score = 0;
			}
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

		if (mgeptr) {//cas des éléments héritant de MobileGameplayElement
			
			fEptr = mgeptr; //On teste leur heritage en focusable Element pour savoir s'ils sont traversable
			if (!fEptr->getTraversable()) {
				//Si on cherche à tester les collisions d'un MobileGameplayElement
				if (MobileGameplayElementPointer) {
					//si l'élément collider  est identique à l'element testé
					if (getInnerBounds(D, mgeptr->getSprite()->getGlobalBounds()) == ActualBox) {
						//on passe à l'élément suivant
						continue;
					}
				}

				//Dans le cas d'un Block
				blptr = dynamic_cast<Block*>(mgeptr);
				if (blptr) {
					//Si on ne traverse pas les blocks
					//Ou que l'on marche sur les blocks et que l'on test une collision vers le bas
					if (!TraverseBlock || (D == Direction::BAS && MarcheSurBlock)) {
						if (collisionBox.intersects(getInnerBounds(OpposeD, blptr->getSprite()->getGlobalBounds()))) {
							return blptr;
						}
					}
					continue;
				}
				else if (collisionBox.intersects(getInnerBounds(OpposeD, mgeptr->getSprite()->getGlobalBounds()))) {

					return mgeptr;
				}
			}
		}
		else { // cas opposé (Bouteilles)
			fEptr = dynamic_cast<FocusableElement*>(grabbablesETInhalables.at(i));
			if (!fEptr->getTraversable()) {
				if (collisionBox.intersects(getInnerBounds(OpposeD, fEptr->getSprite()->getGlobalBounds()))) {
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
	if (PlayerPointer == NULL && collisionBox.intersects(getInnerBounds(OpposeD, player->getSprite()->getGlobalBounds()))) {
		//cout << "Colliding\n";

		return player;
	}
	//cout << "Not Colliding\n";
#pragma endregion 

	return NULL;
}

GameObject* Scene::testEncounter(GameObject*e, Direction D, int margin)
{
	Direction OpposeD = Direction::HAUT;
	switch (D)
	{
	case Direction::HAUT:
		OpposeD = Direction::BAS;
		break;
	case Direction::BAS:
		OpposeD = Direction::HAUT;
		break;
	case Direction::GAUCHE:
		OpposeD = Direction::DROITE;
		break;
	case Direction::DROITE:
		OpposeD = Direction::GAUCHE;
		break;
	default:
		break;
	}
	FloatRect collisionBox, ActualBox;
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

	//Ajustement des zones de collision
	collisionBox = getOuterBounds(D, collisionBox, margin);
	ActualBox = getOuterBounds(D, ActualBox, margin);

#pragma region boundery_collision
	/* TODO */

#pragma endregion

#pragma region entity_collision
	if (!TraverseMur) {
		Mur* MurPtr;
		for (int i = 0; i < murs.size(); i++) {
			MurPtr = murs.at(i);
			if (collisionBox.intersects(getInnerBounds(OpposeD, MurPtr->getSprite()->getGlobalBounds()))) {
				//cout << "Colliding\n";
				return MurPtr;
			}
		}
	}

	OneWay* oneWayPtr;
	for (int i = 0; i < oneWays.size(); i++) {
		oneWayPtr = oneWays.at(i);
		if (!ActualBox.intersects(oneWayPtr->getSprite()->getGlobalBounds()) && D == oneWayPtr->getBlockDirection() && collisionBox.intersects(getInnerBounds(OpposeD, oneWayPtr->getSprite()->getGlobalBounds()))) {
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

		if (mgeptr) {//cas des éléments héritant de MobileGameplayElement

			fEptr = mgeptr; //On teste leur heritage en focusable Element pour savoir s'ils sont traversable
			if (!fEptr->getTraversable()) {
				//Si on cherche à tester les collisions d'un MobileGameplayElement
				if (MobileGameplayElementPointer) {
					//si l'élément collider  est identique à l'element testé
					if (getInnerBounds(D, mgeptr->getSprite()->getGlobalBounds()) == ActualBox) {
						//on passe à l'élément suivant
						continue;
					}
				}

				//Dans le cas d'un Block
				blptr = dynamic_cast<Block*>(mgeptr);
				if (blptr) {
					//Si on ne traverse pas les blocks
					//Ou que l'on marche sur les blocks et que l'on test une collision vers le bas
					if (!TraverseBlock || (D == Direction::BAS && MarcheSurBlock)) {
						if (collisionBox.intersects(getInnerBounds(OpposeD, blptr->getSprite()->getGlobalBounds()))) {
							return blptr;
						}
					}
					continue;
				}
				else if (collisionBox.intersects(getInnerBounds(OpposeD, mgeptr->getSprite()->getGlobalBounds()))) {

					return mgeptr;
				}
			}
		}
		else { // cas opposé (Bouteilles)
			fEptr = dynamic_cast<FocusableElement*>(grabbablesETInhalables.at(i));
			if (!fEptr->getTraversable()) {
				if (collisionBox.intersects(getInnerBounds(OpposeD, fEptr->getSprite()->getGlobalBounds()))) {
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
	if (PlayerPointer == NULL && collisionBox.intersects(getInnerBounds(OpposeD, player->getSprite()->getGlobalBounds()))) {
		//cout << "Colliding\n";

		return player;
	}
	//cout << "Not Colliding\n";
#pragma endregion 

	return NULL;
}

int Scene::update(RenderWindow& GM, vector <Event>EventPool)
{

	/*
	enum sceneOutput {RienASignaler = -1,
		QuickSave = -2,
		ReloadPrevious = -3,
		Exit = -4,
		Restart = -5
	};
	i on retourne 0 ou Plus, alorS on retourne le score
	*/
	int retour = sceneOutput::RienASignaler;
	Event event;

	// cout << EventPool.size() << endl;
	while(EventPool.size() != 0)
	{
		event = EventPool.back();
		switch (event.type)
		{
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


			//anciens paramêtres, ceux la sont présents dans le menu accessible via Echape
			reload = R ou num5
			Quicksave = Q ou num2
			Exit = E ou Echape
			Restart = T ou num8
			
			*/
			if (event.key.code == Keyboard::Down) {
				/*Si on appuis sur la fleche du bas, 
				on doit savoir si 'lon marche sur un 
				switch ou non.

				Etape 1 : convertir les switchs en gameObject 
				afin d'etre acceptés en paramêtre de walkon
				*/
				vector <GameObject*> goptr;
				for (int i = 0; i < switches.size(); i++)
				{
					goptr.push_back(switches.at(i));
				}
				/*
				Etape 2 : Si l'on est bien sur un switch, alors on l'active
				sinon on vide notre couleur
				*/
				if (walkOn(player, goptr)) {
					// cout << "switchColor" << endl;
					switches.at(0)->interact(this);
				}
				else {
					// cout << "discard" << endl;
					if (player->getBringColor() != NOCOLOR) {
						player->setBringColor(NOCOLOR);
					}
				}
				
			}
			else if (event.key.code == Keyboard::RControl) {
				// cout << "Inhale/Hexale" << endl;
				if (player->getBringSomething()) {
					// cout << "hexaling" << endl;

					if(player->getBringColor() == NOCOLOR){
						// cout << "entity" << endl;
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
						// cout << "color" << endl;
						FloatRect interactionBox = player->getInteractionBox();
						for (int i = 0; i < grabbablesETInhalables.size() && player->getBringSomething(); i++)
						{
							if (interactionBox.intersects(grabbablesETInhalables.at(i)->getSprite()->getGlobalBounds())) {
								
								MobileGameplayElement* mpptr = dynamic_cast <MobileGameplayElement*>(grabbablesETInhalables.at(i));
								if (mpptr && mpptr->getColor() == NOCOLOR && mpptr->getPaintable()) {
									// cout << "Transfert possible "<< endl;
									mpptr->setColor(player->getBringColor());
									player->setBringColor(NOCOLOR);
								}
								else {
									// cout << "Transfert impossible " << endl;
								}
							}
						}
					}
				}
				else {
					// cout << "Inhaling" << endl;
					FloatRect interactionBox = player->getInteractionBox();

					for (int i = 0; i < grabbablesETInhalables.size() && !player->getBringSomething(); i++)
					{
						if (interactionBox.intersects(grabbablesETInhalables.at(i)->getSprite()->getGlobalBounds())) {
							// cout << "found something to inhale" << endl;
							Bouteille* btptr = dynamic_cast <Bouteille* >(grabbablesETInhalables.at(i));
							if (btptr) {
								if (btptr->getInhalable()) {
									// cout << "Pick Color" << endl;
									player->setBringColor(btptr->getColor());
								}
								else {
									// cout << "bouteille vivante" << endl;
								}
							}
							else {
								Block * blptr = dynamic_cast <Block*>(grabbablesETInhalables.at(i));
								if (blptr && blptr->getVivant()) {
									// cout << "block vivant" << endl;
								}
								else {
									MobileGameplayElement* mpptr = dynamic_cast <MobileGameplayElement*>(grabbablesETInhalables.at(i));
									if (mpptr->getColor() != NOCOLOR) {
										// cout << "Pick Entity's color" << endl;
										player->setBringColor(mpptr->getColor());
										mpptr->setColor(NOCOLOR);
									}
									else {
										// cout << "Pick Entity" << endl;
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
			else if (event.key.code == Keyboard::S || event.key.code == Keyboard::Numpad1) {
				cout << "Select" << endl;
				//pas encore implémenté
			}
			else if (event.key.code == Keyboard::L || event.key.code == Keyboard::Numpad4) {
				cout << "Lock" << endl;
				//pas encore implémenté
			}
			else if (event.key.code == Keyboard::N || event.key.code == Keyboard::Numpad2) {
				cout << "cancel" << endl;
				//pas encore implémenté
			}
			else if (event.key.code == Keyboard::O || event.key.code == Keyboard::Numpad5) {
				cout << "confirm" << endl;
				//pas encore implémenté
			}
			break;
		default:
			break;
		}
		EventPool.pop_back();
		EventPool.shrink_to_fit();

	}


	player->update(this);

	//Mise a jour de tout les éléments dynamiques
	for (int i = 0; i < grabbablesETInhalables.size(); i++)
	{
		//si ils héritent de MobileGameplayElement
		MobileGameplayElement* mgeptr = dynamic_cast<MobileGameplayElement*>(grabbablesETInhalables.at(i));
		if (mgeptr) {
			mgeptr->update(this);
			continue;
		}
	}

	if (score <= 0)//si on meurt
	{
		retour = sceneOutput::Restart;
	}
		

	if (goals.size() == 0)//si on gagne
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

vector<Mur*> Scene::getMurs()
{
	return murs;
}

void Scene::setMurs(vector<Mur*>m)
{
	murs = m;
}

vector<OneWay*> Scene::getOneWays()
{
	return oneWays;
}

void Scene::setOneWays(vector<OneWay*>w)
{
	oneWays = w;
}

vector<spike*> Scene::getSpikes()
{
	return spikes;
}

void Scene::setSpikes(vector<spike*>s)
{
	spikes = s;
}

vector<Switch*> Scene::getSwiches()
{
	return switches;
}

void Scene::setSwiches(vector<Switch*>s)
{
	switches = s;
}

vector<Goal*> Scene::getGoals()
{
	return goals;
}

void Scene::setGoals(vector<Goal*>g)
{
	goals = g;
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

