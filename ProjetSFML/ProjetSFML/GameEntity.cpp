#include "GameEntity.h"

GameEntity::GameEntity():GameObject()
{
	traversable = false;
}

GameEntity::GameEntity(bool t):GameObject()
{
	traversable = t;
}

bool GameEntity::getTraversable()
{
	return traversable;
}

void GameEntity::setTraversable(bool t)
{
  traversable= t;
}

void GameEntity::ActOnCollide()
{
	cout << "Outch Collision" << endl;
}
