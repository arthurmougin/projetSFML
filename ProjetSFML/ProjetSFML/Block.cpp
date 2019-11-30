#include "Block.h"
#include "Scene.h"

Block::Block():MobileGameplayElement(false, false, true, true, true, 4, true, true, false, NOCOLOR)
{
	//cout << traversable;

}

Block::Block(GameColor gc) : MobileGameplayElement(false, false, true, true, true, 4, true, true, false, gc)
{
	//cout << traversable;
}

Block::Block(
	bool paramvivant
):MobileGameplayElement(false, false, !paramvivant, !paramvivant, true, 4, true, true, false, NOCOLOR)
{
	//cout <<"1speed:"<< speed << endl;
	vivant = paramvivant;
	//cout << traversable;
}

Block::Block(
	bool paramvivant, GameColor gc
) : MobileGameplayElement(false, false, !paramvivant, !paramvivant, true, 4, true, true, false, gc)
{
	//cout <<"2speed:"<< speed << endl;
	vivant = paramvivant;
	//cout << traversable;
}

Block::Block(
	Vector2f position, Texture texture, IntRect textrect
)
	:MobileGameplayElement( false, false, true, true, true, 4, true, true, false, position, texture, textrect, true, true, NOCOLOR)
{
	//cout <<"3speed:"<< speed << endl;
	traversable = false;
}

Block::Block(
	bool paramvivant, Vector2f position, Texture texture, 
	IntRect textrect
)
	: MobileGameplayElement(false, false, !paramvivant, 6, true, true, false, false, 1, position, texture, textrect, true, true, NOCOLOR)
	//bool hateW, bool heavii, bool fly, double Speed, bool TraverseB,bool TraverseM, bool MarcheSurB, bool traversable, int intervalframe,Vector2f position, Texture texture, IntRect textrect, GameColor gc)
{
	vivant = paramvivant;
	//cout <<"4speed:"<< speed << endl;
	traversable = false;
}

Block::Block(
	GameColor gc, Vector2f position, Texture texture, 
	IntRect textrect
)
	: MobileGameplayElement(false, false, true, 6, true, true, true, true, 1, position, texture, textrect, true, true, gc)
{
	//cout << traversable;
	//cout <<"5speed:"<< speed << endl;
	traversable = false;
}

Block::Block(
	bool paramvivant, GameColor gc, Vector2f position, 
	Texture texture, IntRect textrect
)
	: MobileGameplayElement(false, false, true, 6, true, true, false, true, 1, position, texture, textrect, !paramvivant, !paramvivant, gc)
{

	//cout <<"6speed:"<< speed << endl;
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

void Block::update(Scene*scene)
{
	initDirection();
	bool playererGoingLeft = scene->getPlayer().goingLeft();
	bool switchMovement = false;

	if (SwitchMouvementClock.getElapsedTime().asSeconds() > SwitchMouvementDelay) {
		switchMovement = true;
		SwitchMouvementClock.restart();
	}

	//Detection de l'état et mise à jour de ce dernier
	switch (movingState)
	{
	case IDLE:
		//cout << "IDLE ->";
			switch (color)
			{
			case NOCOLOR:
				//do nothing
				break;
			case ROUGE:
				//change de direction
				setMovingState(MOVING_UP);
				SwitchMouvementClock.restart();
				break;
			case BLEU:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_LEFT);
				else
					setMovingState(MOVING_RIGHT);

				SwitchMouvementClock.restart();
				break;
			case JAUNE:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_UP_LEFT);
				else
					setMovingState(MOVING_UP_RIGHT);
				SwitchMouvementClock.restart();
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_LEFT:
		//cout << "MOVING_LEFT ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				setMovingState(IDLE);
				break;
			case ROUGE:
				//change de direction
				setMovingState(MOVING_UP);
				break;
			case BLEU:

				if (!switchMovement)
					setMovingState(MOVING_LEFT);
				else
					setMovingState(MOVING_RIGHT);
				break;
			case JAUNE:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_UP_LEFT);
				else
					setMovingState(MOVING_UP_RIGHT);
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_RIGHT:
		//cout << "MOVING_RIGHT ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				setMovingState(IDLE);
				break;
			case ROUGE:
				//change de direction
				setMovingState(MOVING_UP);
				break;
			case BLEU:
				if (switchMovement)
					setMovingState(MOVING_LEFT);
				else
					setMovingState(MOVING_RIGHT);
				break;
			case JAUNE:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_UP_LEFT);
				else
					setMovingState(MOVING_UP_RIGHT);
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_UP:
		//cout << "MOVING_UP ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				setMovingState(IDLE);
				break;
			case ROUGE:
				if(!switchMovement)
					setMovingState(MOVING_UP);
				else
					setMovingState(MOVING_DOWN);
				break;
			case BLEU:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_LEFT);
				else
					setMovingState(MOVING_RIGHT);
				break;
			case JAUNE:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_UP_LEFT);
				else
					setMovingState(MOVING_UP_RIGHT);
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_DOWN:
		//cout << "MOVING_DOWN ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				setMovingState(IDLE);
				break;
			case ROUGE:
				if (switchMovement)
					setMovingState(MOVING_UP);
				else
					setMovingState(MOVING_DOWN);
				break;
			case BLEU:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_LEFT);
				else
					setMovingState(MOVING_RIGHT);
				break;
			case JAUNE:
				//change de direction
				if (playererGoingLeft)
					setMovingState(MOVING_UP_LEFT);
				else
					setMovingState(MOVING_UP_RIGHT);
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_UP_LEFT:
		//cout << "MOVING_UP_LEFT ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				movingState = IDLE;
				break;
			case ROUGE:
				//change de direction
				movingState = MOVING_UP;
				break;
			case BLEU:
				//change de direction
				if (playererGoingLeft)
					movingState = MOVING_LEFT;
				else
					movingState = MOVING_RIGHT;
				break;
			case JAUNE:
				if (!switchMovement)
					movingState = MOVING_UP_LEFT;
				else
					movingState = MOVING_DOWN_RIGHT;
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_UP_RIGHT:
		//cout << "MOVING_UP_RIGHT ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				movingState = IDLE;
				break;
			case ROUGE:
				//change de direction
				movingState = MOVING_UP;
				break;
			case BLEU:
				//change de direction
				if (playererGoingLeft)
					movingState = MOVING_LEFT;
				else
					movingState = MOVING_RIGHT;
				break;
			case JAUNE:
				if (!switchMovement)
					movingState = MOVING_UP_RIGHT;
				else
					movingState = MOVING_DOWN_LEFT;
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_DOWN_LEFT:
		//cout << "MOVING_DOWN_LEFT ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				movingState = IDLE;
				break;
			case ROUGE:
				//change de direction
				movingState = MOVING_UP;
				break;
			case BLEU:
				//change de direction
				if (playererGoingLeft)
					movingState = MOVING_LEFT;
				else
					movingState = MOVING_RIGHT;
				break;
			case JAUNE:
				if (switchMovement)
					movingState = MOVING_UP_RIGHT;
				else
					movingState = MOVING_DOWN_LEFT;
				break;
			default:
				//do nothing
				break;
			}
		break;
	case MOVING_DOWN_RIGHT:
		//cout << "MOVING_DOWN_RIGHT ->";
			switch (color)
			{
			case NOCOLOR:
				//change de direction
				movingState = IDLE;
				break;
			case ROUGE:
				//change de direction
				movingState = MOVING_UP;
				break;
			case BLEU:
				//change de direction
				if (playererGoingLeft)
					movingState = MOVING_LEFT;
				else
					movingState = MOVING_RIGHT;
				break;
			case JAUNE:
				if (switchMovement)
					movingState = MOVING_UP_LEFT;
				else
					movingState = MOVING_DOWN_RIGHT;
				break;
			default:
				//do nothing
				break;
			}
		break;
	default:
		//cout << "default ->";
		movingState = IDLE;
		break;
	}



	/**/
	//mise a jour du deplacement en fonction de l'etat de deplacement
	switch (movingState)
	{
	case IDLE:
		//cout << " IDLE" << endl;
		break;
	case MOVING_LEFT:
		//cout << " MOVING_LEFT" << endl;
		moveTo(Direction::GAUCHE);

		break;
	case MOVING_RIGHT:
		//cout << " MOVING_RIGHT" << endl;
		moveTo(Direction::DROITE);

		break;
	case MOVING_UP:
		//cout << " MOVING_UP" << endl;
		moveTo(Direction::HAUT);

		break;
	case MOVING_DOWN:
		//cout << " MOVING_DOWN" << endl;
		moveTo(Direction::BAS);

		break;
	case MOVING_UP_LEFT:
		//cout << " MOVING_UP_LEFT" << endl;
		moveTo(Direction::HAUT);
		moveTo(Direction::GAUCHE);

		break;
	case MOVING_UP_RIGHT:
		//cout << " MOVING_UP_RIGHT" << endl;
		moveTo(Direction::HAUT);
		moveTo(Direction::DROITE);

		break;
	case MOVING_DOWN_LEFT:
		//cout << " MOVING_DOWN_LEFT" << endl;
		moveTo(Direction::BAS);
		moveTo(Direction::GAUCHE);

		break;
	case MOVING_DOWN_RIGHT:
		//cout << " MOVING_DOWN_RIGHT" << endl;
		moveTo(Direction::BAS);
		moveTo(Direction::DROITE);

		break;
	default:
		//cout << " default" << endl;
		break;
	}


	//ProtectWalkingOnEntity


	if (movingState != IDLE) {

		GameObject* walker = scene->testEncounter(this, Direction::HAUT,20);

		if (walker) {
			//cout << "colliding walker" << endl;
			MobileGameplayElement* dynamicWalker = dynamic_cast<MobileGameplayElement*>(walker);
			if (dynamicWalker) {
				//cout << "colliding dynamicWalker walker" << endl;
				FloatRect blockBounds = this->getSprite()->getGlobalBounds();
				FloatRect localGB = dynamicWalker->getSprite()->getGlobalBounds();
				float LocalDelta = (blockBounds.top - localGB.height) - localGB.top;
				dynamicWalker->getSprite()->move(Vector2f(0, LocalDelta));
			}
			else {
				Player* dynamicplayingWalker = dynamic_cast<Player*>(walker);
				if (dynamicplayingWalker) {
					//cout << "colliding dynamicplayingWalker walker" << endl;
					FloatRect blockBounds = this->getSprite()->getGlobalBounds();
					FloatRect localGB = dynamicplayingWalker->getSprite()->getGlobalBounds();
					float LocalDelta = (blockBounds.top - localGB.height) - localGB.top;
					dynamicplayingWalker->getSprite()->move(Vector2f(0, LocalDelta));
				}
			}
		}
	} 


	//updatePos(9.8 / 12);



	/**/
	MobileGameplayElement::update(scene);
}
