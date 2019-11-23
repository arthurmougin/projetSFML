#pragma once
#include "FocusableElement.h"

class PaintableElement:public FocusableElement
{
protected:
	bool paintable;
	GameColor color = NOCOLOR;
	bool inhalable;
public:
	PaintableElement();
	PaintableElement(bool, bool);
};

