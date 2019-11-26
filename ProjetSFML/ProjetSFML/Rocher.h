#pragma once
#include "MobileGameplayElement.h"
class Scene;
class Rocher : public MobileGameplayElement
{
public:
	Rocher();
	Rocher(Vector2f, Texture, IntRect);

	void update(Scene*);
};

