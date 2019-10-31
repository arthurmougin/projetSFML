#pragma once
#include "GameEntity.h"
class GameplayElement:public GameEntity
{
private:
	// Pour le selector
	bool focused;
	bool locked;

	// pour la peinture
	bool Paintable; // rocher, block vivant et bouteilles = false
	Color color; // rocher et block vivant = couleur spécifique non incluse
	bool inhalable; // Bouteille vivante, rocher et block vivant = false

	//pour le déplacement
	bool grabbable; // faux pour les bouteilles et le block vivant
	bool HateWalls; // différencie les éléments qui ne peuvent etre placés dans un mur

public:
	GameplayElement();
	GameplayElement(bool, bool, bool, Color, bool, bool);

	bool getFocused();
	void setFocused(bool);
	bool getLocked();
	void setLocked(bool);
	bool getPaintable();
	void setPaintable(bool);
	Color getColor();
	void setColor(Color);
	bool getInhalable();
	void setInhalable(bool);
	bool getgrabbable();
	void setgrabbable(bool);
	bool getHateWalls();
	void setHateWalls(bool);

	void claimFocus();
	void grab();
};

