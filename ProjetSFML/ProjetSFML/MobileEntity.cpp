#include "MobileEntity.h"

MobileEntity::MobileEntity():GameObject()
{
	flying = TraverseBlock = false;
	speed = 1;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = TraverseMur = false;
	Hauteur = 0;
}

MobileEntity::MobileEntity(bool fly, float Speed, bool TraverseB, bool TraverseM, bool MarcheSurB):GameObject()
{
	flying = fly;
	TraverseBlock = TraverseB;
	speed = Speed;
	acceleration = direction = Vector2f(0, 0);
	MarcheSurBlock = MarcheSurB;
	TraverseMur = TraverseM;
	Hauteur = 0;
}

MobileEntity::MobileEntity(bool fly, float myspeed, Vector2f myAcceleration, Vector2f myDirection, bool TravB, bool TravM, bool MarchB, float Hight):GameObject()
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

void MobileEntity::moveTo(int d)
{

	switch (d) {
	case HAUT:
			direction.y = -1;
		break;
	case BAS:
			Hauteur = 1;
			direction.y = 1;
		
		break;
	case GAUCHE:
			direction.x = -1;
		break;
	case DROITE:
			direction.x = 1;
		break;
	default:
		cout << "direction inconnue : " << d << endl;
		break;
	}
}

void MobileEntity::updatePos(float G)
{
	if (Hauteur != 0) {
		acceleration.y - G;
	}
	else {
		acceleration.y = 0;
	}

	move((direction.x * speed) + acceleration.x, (direction.y * speed) + acceleration.y);

	direction = Vector2f(0, 0);
}

bool MobileEntity::getFlying()
{
	return flying;
}

void MobileEntity::setFlying(bool f)
{
	flying = f;
}

float MobileEntity::getSpeed()
{
	return speed;
}

void MobileEntity::setSpeed(float s)
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

float MobileEntity::getHauteur()
{
	return Hauteur;
}

void MobileEntity::setHauteur(float h)
{
	Hauteur = h;
}

Sprite MobileEntity::getFantome()
{
	return Fantome;
}

void MobileEntity::setFantome(Sprite f)
{
	Fantome = f;
}
