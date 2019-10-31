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

bool MobileEntity::testCollision(int D, float G, vector <ElementContainer> es)
{
	Fantome.setPosition(this->getPosition());
	float dx, dy;
	dx = dy = 0;
	switch (D)
	{case HAUT:
		dy = -1;
		break;
	case BAS:
		dy = 1;
		break;
	case GAUCHE:
		dx = -1;
		break;
	case DROITE:
		dx = 1;
		break;
	default:
		break;
	}

	if (Hauteur != 0) {
		Fantome.move((dx * speed) + 0, (dy * speed) + acceleration.y - G);
	}
	else {
		acceleration.y = 0;
		Fantome.move((dx * speed) + 0, (dy * speed) + acceleration.y);
	}

	for (int i = 0; i < es.size(); i++)
	{
		switch (es.at(i).type) {
		case MUR:
			//si l'entité ne traverse pas les murs et que le fantome est en collision avec les murs
			if (!TraverseMur && es.at(i).mur.getGlobalBounds().intersects(Fantome.getGlobalBounds()))
				return true;
			break;
		case PLAYER:
			break;
		default:
			cout << "type inconnu dans la collision" << endl;
			break;
		}
	}



	return false;
}

void MobileEntity::moveTo(int d, float G, vector <ElementContainer> es)
{

	switch (d) {
	case HAUT:
		if (testCollision(d,G, es))
			direction.y = 0;
		else
			direction.y = -1;
		break;
	case BAS:
		if (testCollision(d, G, es))
		{
			Hauteur = 0;
			direction.y = 0;
		}
		else
		{
			Hauteur = 1;
			direction.y = 1;
		}
		break;
	case GAUCHE:
		if (testCollision(d, G, es))
			direction.x = 0;
		else
			direction.x = -1;
		break;
	case DROITE:
		if (testCollision(d, G, es))
			direction.x = 0;
		else
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
