#include "Rocher.h"

Rocher::Rocher():MobileGameplayElement()
{
}

Rocher::Rocher(Vector2f position, Texture texture, IntRect textrect):MobileGameplayElement(true,true,15,true,false,false,false,1, position, texture, textrect)
{
}
