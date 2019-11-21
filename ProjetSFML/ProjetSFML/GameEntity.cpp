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

GameEntity::GameEntity(bool t, Vector2f pos, Texture tex, IntRect rect) : GameObject(pos, tex, rect)
{
	traversable = t;
}


void GameEntity::interact()
{
	cout << "Interaction Yeah" << endl;
}

void GameEntity::ActOnCollide()
{
	cout << "Outch Collision" << endl;
}
