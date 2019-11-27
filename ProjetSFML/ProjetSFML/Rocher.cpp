#include "Rocher.h"
#include "Scene.h"

Rocher::Rocher():MobileGameplayElement()
{
}
//bool hateW, bool heavii, bool fly, double Speed, bool TraverseBlock, bool TraverseMur, bool MarcheSurBlock, bool traversable, Vector2f position, Texture texture, IntRect textrect
Rocher::Rocher(Vector2f position, Texture texture, IntRect textrect):
	MobileGameplayElement(true,true,false,15,false,false,false,false, position, texture, textrect, NOCOLOR)
{
}

