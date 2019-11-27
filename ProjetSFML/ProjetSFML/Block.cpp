#include "Block.h"

Block::Block():MobileGameplayElement(false, false, true, true, true, 15, true, true, false, NOCOLOR)
{
	//cout << traversable;

}

Block::Block(GameColor gc) : MobileGameplayElement(false, false, true, true, true, 15, true, true, false, gc)
{
	//cout << traversable;
}

Block::Block(
	bool paramvivant
):MobileGameplayElement(false, false, !paramvivant, !paramvivant, true, 15, true, true, false, NOCOLOR)
{
	vivant = paramvivant;
	//cout << traversable;
}

Block::Block(
	bool paramvivant, GameColor gc
) : MobileGameplayElement(false, false, !paramvivant, !paramvivant, true, 15, true, true, false, gc)
{
	vivant = paramvivant;
	//cout << traversable;
}

Block::Block(
	Vector2f position, Texture texture, IntRect textrect
)
	:MobileGameplayElement( false, false, true, true, true, 15, true, true, false, position, texture, textrect, NOCOLOR)
{
	traversable = false;
}

Block::Block(
	bool paramvivant, Vector2f position, Texture texture, 
	IntRect textrect
)
	: MobileGameplayElement(false, false, !paramvivant, 15, true, true, false, false, 1, position, texture, textrect, NOCOLOR)
	//bool hateW, bool heavii, bool fly, double Speed, bool TraverseB,bool TraverseM, bool MarcheSurB, bool traversable, int intervalframe,Vector2f position, Texture texture, IntRect textrect, GameColor gc)
{
	vivant = paramvivant;
	traversable = false;
}

Block::Block(
	GameColor gc, Vector2f position, Texture texture, 
	IntRect textrect
)
	: MobileGameplayElement(false, false, true, true, true, 15, true, true, false, position, texture, textrect, gc)
{
	//cout << traversable;
	traversable = false;
}

Block::Block(
	bool paramvivant, GameColor gc, Vector2f position, 
	Texture texture, IntRect textrect
)
	: MobileGameplayElement(false, false, !paramvivant, !paramvivant, true, 15, true, true, false, position, texture, textrect, gc)
{
	vivant = paramvivant;
	traversable = false;

}

bool Block::getVivant()
{
	return vivant;
}

void Block::setVivant(bool v)
{
	vivant = v;
	setFlying(!v);
	setInhalable(!v);
	setPaintable(!v);
}
