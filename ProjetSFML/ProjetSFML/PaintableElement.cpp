#include "PaintableElement.h"

PaintableElement::PaintableElement():FocusableElement()
{
}

PaintableElement::PaintableElement(bool paintbl, bool inhalabl):FocusableElement()
{
	paintable = paintbl;
	inhalable = inhalabl;
}

PaintableElement::PaintableElement(bool paintbl, bool inhalabl, bool trav, Vector2f pos, Texture tex, IntRect rect) : FocusableElement(trav, pos, tex, rect)
{
	paintable = paintbl;
	inhalable = inhalabl;
}

PaintableElement::PaintableElement(bool paintbl, bool inhalabl, bool trav, int intervalFramce, Vector2f pos, Texture tex, IntRect rect) : FocusableElement(trav, intervalFramce, pos, tex, rect)
{
	paintable = paintbl;
	inhalable = inhalabl;
}

PaintableElement::PaintableElement(bool paintbl, bool inhalabl, GameColor gcolor)
{
	paintable = paintbl;
	inhalable = inhalabl;
	setColor(gcolor);
}

PaintableElement::PaintableElement(bool paintbl, bool inhalabl, GameColor gcolor, bool trav, Vector2f pos, Texture tex, IntRect rect) : FocusableElement(trav, pos, tex, rect)
{
	paintable = paintbl;
	inhalable = inhalabl;
	setColor(gcolor);
}

PaintableElement::PaintableElement(bool paintbl, bool inhalabl, GameColor gcolor, bool trav, int intervalFramce, Vector2f pos, Texture tex, IntRect rect) : FocusableElement(trav, intervalFramce, pos, tex, rect)
{
	paintable = paintbl;
	inhalable = inhalabl;
	setColor(gcolor);
}

bool PaintableElement::getPaintable()
{
	return paintable;
}

void PaintableElement::setPaintable(bool p)
{
	paintable = p;
}

GameColor PaintableElement::getColor()
{
	return color;
}

void PaintableElement::setColor(GameColor c)
{
	color = c;
	this->sprite.setColor( getColorFromEnum(c) );
}

bool PaintableElement::getInhalable()
{
	return inhalable;
}

void PaintableElement::setInhalable(bool i)
{
	inhalable = i;
}
