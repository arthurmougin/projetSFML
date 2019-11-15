#include "Mur.h"

Mur::Mur():GameObject()
{
}

Mur::Mur(Vector2f Pos):GameObject()
{
	setPosition(Pos);
}

Mur::Mur(Vector2f pos, Texture tex, IntRect rect):GameObject(pos,tex,rect)
{
	/*setPosition(pos);
	setTexture(tex);
	setTextureRect(rect);*/
}
/**
void Mur::update()
{
}
/**/