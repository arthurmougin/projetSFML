#include "Rocher.h"
#include "Scene.h"

Rocher::Rocher():MobileGameplayElement()
{
}
//bool hateW, bool heavii, bool fly, double Speed, bool TraverseBlock, bool TraverseMur, bool MarcheSurBlock, bool traversable, Vector2f position, Texture texture, IntRect textrect
Rocher::Rocher(Vector2f position, Texture texture, IntRect textrect):
	MobileGameplayElement(true,true,false,15,false,false,false,false, position, texture, textrect)
{
}

void Rocher::update(Scene* scene)
{
	cout << "update Rocher" << endl;
	MobileEntity* castableThis = this;

	if (!flying) { //system de chute pour les éléments non volants
		cout << "testFalling" << endl;
		/*
		Ce code est inspiré de player.cpp,
		cependant des propriétés doivent etre ajoutées pour s'adapter au type nonPlayer
		*/
		bool testcollbas = scene->testCollide(castableThis, Direction::BAS);
		if (testcollbas) {
			cout << "notFalling" << endl;
			if (getHauteur() != 0) {
				setHauteur(0);
				float localY = castableThis->getSprite()->getPosition().y, LocalDelta;
				localY = (int(localY) % 160) + localY - int(localY);
				//cout << "localy : " << localY << endl;
				if (localY < (80)) {
					localY = -localY + 32;
				}
				else {
					localY = 160 - localY - 32;
				}
				castableThis->getSprite()->move(Vector2f(0, localY));
			}
			movingState = IDLE;
		}
		else {
			cout << "Falling" << endl;

			if (getHauteur() == 0) {
				setHauteur(1);
			}
			movingState = FALLING;
		}
	}
	

	updatePos(9.8 / 12);
}
