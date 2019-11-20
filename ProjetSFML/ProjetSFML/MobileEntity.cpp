#include "MobileEntity.h"

MobileEntity::MobileEntity():GameObject()
{
	flying = TraverseBlock = false;
	speed = 10;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = TraverseMur = false;
	Hauteur = 0;
}

MobileEntity::MobileEntity(Vector2f pos, Texture tex, IntRect rect) :GameObject(pos, tex, rect)
{
	flying = TraverseBlock = false;
	speed = 10;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = TraverseMur = false;
	Hauteur = 0;
	Fantome.setTexture(tex);
	Fantome.setTextureRect(rect);
}

MobileEntity::MobileEntity(bool fly, double Speed, bool TraverseB, bool TraverseM, bool MarcheSurB):GameObject()
{
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;

}

MobileEntity::MobileEntity(bool fly, double Speed, bool TraverseB, bool TraverseM, bool MarcheSurB, Vector2f pos, Texture tex, IntRect rect) :GameObject(pos, tex, rect)
{
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;
	Fantome.setTexture(tex);
	Fantome.setTextureRect(rect);
}

MobileEntity::MobileEntity(bool fly, double myspeed, Vector2f myAcceleration, Vector2f myDirection, bool TravB, bool TravM, bool MarchB, double Hight):GameObject()
{
	flying = fly;
	speed = myspeed;
	acceleration = myAcceleration;
	direction = myDirection;
	TraverseBlock = TravB;
	TraverseMur = TravM;
	MarcheSurBlock = MarchB;
	Hauteur = Hight;
}

MobileEntity::MobileEntity(bool fly, double myspeed, Vector2f myAcceleration, Vector2f myDirection, bool TravB, bool TravM, bool MarchB, double Hight, Vector2f pos, Texture tex, IntRect rect) :GameObject(pos, tex, rect)
{
	flying = fly;
	speed = myspeed;
	acceleration = myAcceleration;
	direction = myDirection;
	TraverseBlock = TravB;
	TraverseMur = TravM;
	MarcheSurBlock = MarchB;
	Hauteur = Hight;
	Fantome.setTexture(tex);
	Fantome.setTextureRect(rect);
}

void MobileEntity::moveTo(Direction d)
{
	switch (d) {
	case Direction::HAUT:
		if (Hauteur == 0) {
			Hauteur = 1;
			acceleration.y = -19;
			direction.y = -1;
		}
		break;
	case Direction::BAS:
			direction.y = 1;
		break;
	case Direction::GAUCHE:
			direction.x = -1;
		break;
	case Direction::DROITE:
			direction.x = 1;
		break;
	default:
		cout << "direction inconnue" <<endl;
		break;
	}
}

void MobileEntity::updatePos(double G)
{

	if (Hauteur != 0) {
		acceleration.y += G;
	}
	else {
		acceleration.y = 0;
	}
	//cout << "x:" << sprite.getPosition().x << " y:" << sprite.getPosition().y;
	//cout << "dy:" << direction.y << " ay:" << acceleration.y << "tot:" << (direction.y * speed) + acceleration.y << "h" << Hauteur << endl;
	sprite.move((direction.x * speed) + acceleration.x, (direction.y * speed) + acceleration.y);
	direction = Vector2f(0, 0);
}

Sprite MobileEntity::getUpdatedFantome(Direction d)
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
			myHauteur = 1;
			myDirection.y = -1;
			myAcceleration.y = -19;

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
	if (myHauteur != 0) {
		myAcceleration.y -= 9.8/30;
	}
	else {
		myAcceleration.y = 0;
	}

	Fantome.move((myDirection.x * speed) + myAcceleration.x, (myDirection.y * speed) + myAcceleration.y);
#pragma endregion

	return Fantome;
}

bool MobileEntity::getFlying()
{
	return flying;
}

void MobileEntity::setFlying(bool f)
{
	flying = f;
}

double MobileEntity::getSpeed()
{
	return speed;
}

void MobileEntity::setSpeed(double s)
{
	speed = s;
}

Vector2f MobileEntity::getAcceleration()
{
	return acceleration;
}

void MobileEntity::setAcceleration(Vector2f a)
{
	acceleration = a;
}

Vector2f MobileEntity::getDirection()
{
	return direction;
}

void MobileEntity::setDirection(Vector2f d)
{
	direction = d;
}

bool MobileEntity::getTraverseBlock()
{
	return TraverseBlock;
}

void MobileEntity::setTraverseBlock(bool t)
{
	TraverseBlock = t;
}

bool MobileEntity::getTraverseMur()
{
	return TraverseMur;
}

void MobileEntity::setTraverseMur(bool t)
{
	TraverseMur = t;

}

bool MobileEntity::getMarcheSurBlock()
{
	return MarcheSurBlock;
}

void MobileEntity::setMarcheSurBlock(bool m)
{
	MarcheSurBlock = m;
}

double MobileEntity::getHauteur()
{
	return Hauteur;
}

void MobileEntity::setHauteur(double h)
{
	Hauteur = h;
}

Sprite MobileEntity::getFantome()
{
	Fantome.setPosition(sprite.getPosition());
	Fantome.setScale(sprite.getScale());
	Fantome.setTextureRect(sprite.getTextureRect());
	return Fantome;
}

void MobileEntity::setFantome(Sprite f)
{
	Fantome = f;
}
