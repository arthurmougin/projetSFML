#pragma once
#include "FocusableElement.h"

class PaintableElement:public FocusableElement
{
protected:
	bool paintable = false;
	enum GameColor color = GameColor::NOCOLOR;
	bool inhalable = true;
public:
	PaintableElement();
	PaintableElement(bool, bool);
	PaintableElement(bool, bool, bool, Vector2f, Texture, IntRect);
	PaintableElement(bool, bool, GameColor);
	PaintableElement(bool, bool, GameColor, bool, Vector2f, Texture, IntRect);

	bool getPaintable();
	void setPaintable(bool);
	GameColor getColor();
	void setColor(GameColor);
	bool getInhalable();
	void setInhalable(bool);
};

