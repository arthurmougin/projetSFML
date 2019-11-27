#include "MobileGameplayElement.h"
#include "Scene.h"

MobileGameplayElement::MobileGameplayElement(): PaintableElement(false, false,false)
{
	movingState = FALLING;
	HateWalls = true;
	heavy = false;

	/*
		code dupliqué
	 */
	flying = TraverseBlock = false;
	speed = 15;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = TraverseMur = false;
	Hauteur = 0;
}

MobileGameplayElement::MobileGameplayElement(
	bool hw, bool hv, GameColor gc
) : PaintableElement(false, false, false, gc)
{
	movingState = FALLING;
	HateWalls = hw;
	heavy = hv;

	/*
		code dupliqué
	 */
	flying = TraverseBlock = false;
	speed = 15;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = TraverseMur = false;
	Hauteur = 0;
}

MobileGameplayElement::MobileGameplayElement(
	bool hw, bool hv, bool paintbl, bool inhalabl, GameColor gc
) : PaintableElement(paintbl, inhalabl, false, gc)
{
	movingState = FALLING;
	HateWalls = hw;
	heavy = hv;

	/*
		code dupliqué
	 */
	flying = TraverseBlock = false;
	speed = 15;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = TraverseMur = false;
	Hauteur = 0;
}

MobileGameplayElement::MobileGameplayElement(
	bool hw, bool hv, bool paintbl, bool inhalabl, bool fly, double Speed, 
	bool TraverseB, bool TraverseM, bool MarcheSurB, GameColor gc
): PaintableElement(paintbl, inhalabl, false,gc)
{
	movingState = FALLING;
	HateWalls = hw;
	heavy = hv;

	/*
		code dupliqué
	 */
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;
}

MobileGameplayElement::MobileGameplayElement(
	bool hateW, bool heavii, bool fly, double Speed, bool TraverseB, 
	bool TraverseM, bool MarcheSurB, bool traversable, Vector2f position, 
	Texture texture, IntRect textrect, GameColor gc
):PaintableElement(false,false, gc,traversable, position, texture, textrect)
{
	cout << "traversable" << traversable << endl;
	movingState = FALLING;
	HateWalls = hateW;
	heavy = heavii;


	/*
		code dupliqué
	 */
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;
	Fantome.setTexture(texture);
	Fantome.setTextureRect(textrect);
}

MobileGameplayElement::MobileGameplayElement(
	bool hateW, bool heavii, bool fly, double Speed, bool TraverseB, 
	bool TraverseM, bool MarcheSurB, bool traversable, Vector2f position, 
	Texture texture, IntRect textrect, bool paintbl, bool inhalabl, GameColor gc
):PaintableElement(paintbl, inhalabl, gc, traversable, position, texture, textrect)
{
	cout << "traversable" << traversable << endl;
	movingState = FALLING;
	HateWalls = hateW;
	heavy = heavii;


	/*
		code dupliqué
	 */
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;
	Fantome.setTexture(texture);
	Fantome.setTextureRect(textrect);
}

MobileGameplayElement::MobileGameplayElement(
	bool hateW, bool heavii, bool fly, double Speed, bool TraverseB, 
	bool TraverseM, bool MarcheSurB, bool traversable, int intervalframe, 
	Vector2f position, Texture texture, IntRect textrect, GameColor gc
) :PaintableElement(false, false,  gc, traversable,
	intervalframe, position, texture, textrect)
{
	cout << "traversable " << traversable << endl;

	movingState = FALLING;
	HateWalls = hateW;
	heavy = heavii;

	/*
		code dupliqué
	 */
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;
	Fantome.setTexture(texture);
	Fantome.setTextureRect(textrect);
}

MobileGameplayElement::MobileGameplayElement(
	bool hateW, bool heavii, bool fly, double Speed, bool TraverseB, 
	bool TraverseM, bool MarcheSurB, bool traversable, int intervalframe, 
	Vector2f position, Texture texture, IntRect textrect, bool paintbl, 
	bool inhalabl, GameColor gc
):PaintableElement(paintbl,inhalabl,gc, traversable,
	intervalframe, position, texture, textrect)
{
	cout << "traversable" << traversable << endl;
	movingState = FALLING;
	HateWalls = hateW;
	heavy = heavii;


	/*
		code dupliqué
	 */
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;
	Fantome.setTexture(texture);
	Fantome.setTextureRect(textrect);
}

void MobileGameplayElement::update(Scene* scene)
{
	//cout << "update MobileGamePlayElement" << endl;

	if (!flying) { //system de chute pour les éléments non volants
		/*
		Ce code est inspiré de player.cpp,
		cependant des propriétés doivent etre ajoutées pour s'adapter au type nonPlayer
		*/
		GameObject* testcollbas = scene->testCollide(this, Direction::BAS);
		if (testcollbas) {
			if (getHauteur() != 0 && acceleration.y > 0) {
				setHauteur(0);
				FloatRect colliderGB = testcollbas->getSprite()->getGlobalBounds();
				FloatRect localGB = this->getSprite()->getGlobalBounds();
				float LocalDelta = (colliderGB.top - localGB.height) - localGB.top;
				this->getSprite()->move(Vector2f(0, LocalDelta));
			}

			if (heavy) {

				//Suppresion des éléments sur lesquels l'objet atterrie selon certaines conditions
				MobileGameplayElement* mgeptr = dynamic_cast<MobileGameplayElement*>(testcollbas);
				bool deleted = false;
				if (mgeptr) {
					vector <GameObject*> grabs = scene->getGrabbablesETInhalables();
					
					for (int i = 0; i < grabs.size() && !deleted; i++)
					{
						if (mgeptr->getSprite()->getGlobalBounds() == grabs.at(i)->getSprite()->getGlobalBounds()) {

							grabs.erase(grabs.begin() + i);
							grabs.shrink_to_fit();
							deleted = true;
						}
					}
					scene->setGrabbablesETInhalables(grabs);
				}

				if (!deleted) {
					movingState = IDLE;
				}

			}
			else {
				movingState = IDLE;
			}
			
		}
		else {
			if (getHauteur() == 0) {
				setHauteur(1);
			}
			movingState = FALLING;
		}
	}


	updatePos(9.8 / 12);
}

enum MovingState MobileGameplayElement::getMovingState()
{
	return movingState;
}

void MobileGameplayElement::setMovingState(enum MovingState m)
{
	movingState = m;
}

bool MobileGameplayElement::getHateWalls()
{
	return HateWalls;
}

void MobileGameplayElement::setHateWalls(bool h)
{
	HateWalls = h;
}

bool MobileGameplayElement::getHeavy()
{
	return heavy;
}

void MobileGameplayElement::setHeavy(bool h)
{
	heavy = h;
}


/*

Fonctions dupliquées et adaptées de MobileEntity


*/



void MobileGameplayElement::moveTo(Direction d)
{
	cout << "moveto ";
	switch (d) {
	case Direction::HAUT:
		cout << "HAUT" << endl;

		if (Hauteur == 0) {
			if (!flying) {
				Hauteur = 1;

				acceleration.y = -30;
			}
			direction.y = -1;
		}
		break;
	case Direction::BAS:

		cout << "BAS" << endl;
		direction.y = 1;
		break;
	case Direction::GAUCHE:
		cout << "GAUCHE" << endl;
		direction.x = -1;
		break;
	case Direction::DROITE:

		cout << "DROITE" << endl;
		direction.x = 1;
		break;
	default:
		cout << "direction inconnue" << endl;
		break;
	}
}

void MobileGameplayElement::updatePos(double G)
{

	if (Hauteur != 0 && !flying) {
		acceleration.y += G;
	}
	else {
		acceleration.y = 0;
	}
	//cout << "x:" << sprite.getPosition().x << " y:" << sprite.getPosition().y;
	//cout << "dy:" << direction.y << " ay:" << acceleration.y << "tot:" << (direction.y * speed) + acceleration.y << "h" << Hauteur << endl;
	sprite.move((direction.x * speed) + acceleration.x, (direction.y * speed) + acceleration.y);

}

void MobileGameplayElement::initDirection()
{
	direction = Vector2f(0, 0);
}

Sprite MobileGameplayElement::getUpdatedFantome(Direction d)
{
	double myHauteur = Hauteur;
	Vector2f myDirection(direction), myAcceleration(acceleration);
	Fantome.setPosition(sprite.getPosition());
	Fantome.setScale(sprite.getScale());
	Fantome.setTextureRect(sprite.getTextureRect());

#pragma region moveto
	switch (d) {
	case Direction::HAUT:
		if (myHauteur == 0) {
			if (!flying) {
				myHauteur = 1;
				myAcceleration.y = -30;
			}
			myDirection.y = -1;
		}
		break;
	case Direction::BAS:

		myDirection.y = 1;
		break;
	case Direction::GAUCHE:
		myDirection.x = -1;
		break;
	case Direction::DROITE:
		myDirection.x = 1;
		break;
	default:
		cout << "direction inconnue" << endl;
		break;
	}
#pragma endregion

#pragma region updatepos
	if (myHauteur != 0 && !flying) {
		myAcceleration.y -= 9.8 / 12;
	}
	else {
		myAcceleration.y = 0;
	}

	Fantome.move((myDirection.x * speed) + myAcceleration.x, (myDirection.y * speed) + myAcceleration.y);
#pragma endregion

	return Fantome;
}

bool MobileGameplayElement::getFlying()
{
	return flying;
}

void MobileGameplayElement::setFlying(bool f)
{
	flying = f;
}

double MobileGameplayElement::getSpeed()
{
	return speed;
}

void MobileGameplayElement::setSpeed(double s)
{
	speed = s;
}

Vector2f MobileGameplayElement::getAcceleration()
{
	return acceleration;
}

void MobileGameplayElement::setAcceleration(Vector2f a)
{
	acceleration = a;
}

Vector2f MobileGameplayElement::getDirection()
{
	return direction;
}

void MobileGameplayElement::setDirection(Vector2f d)
{
	direction = d;
}

bool MobileGameplayElement::getTraverseBlock()
{
	return TraverseBlock;
}

void MobileGameplayElement::setTraverseBlock(bool t)
{
	TraverseBlock = t;
}

bool MobileGameplayElement::getTraverseMur()
{
	return TraverseMur;
}

void MobileGameplayElement::setTraverseMur(bool t)
{
	TraverseMur = t;

}

bool MobileGameplayElement::getMarcheSurBlock()
{
	return MarcheSurBlock;
}

void MobileGameplayElement::setMarcheSurBlock(bool m)
{
	MarcheSurBlock = m;
}

double MobileGameplayElement::getHauteur()
{
	return Hauteur;
}

void MobileGameplayElement::setHauteur(double h)
{
	Hauteur = h;
}

Sprite MobileGameplayElement::getFantome()
{
	Fantome.setPosition(sprite.getPosition());
	Fantome.setScale(sprite.getScale());
	Fantome.setTextureRect(sprite.getTextureRect());
	return Fantome;
}

void MobileGameplayElement::setFantome(Sprite f)
{
	Fantome = f;
}
