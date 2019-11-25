#include "Bouteille.h"

Bouteille::Bouteille():PaintableElement(false,false, GameColor::ROUGE)
{
}

Bouteille::Bouteille(GameColor c):PaintableElement(false, false,c)
{
}

Bouteille::Bouteille(bool vrai):PaintableElement(false, vrai, GameColor::ROUGE)
{
}

Bouteille::Bouteille(bool vrai, GameColor c):PaintableElement(false, vrai, c)
{
}

Bouteille::Bouteille(bool vrai, Vector2f pos, Texture tex, IntRect rect) : PaintableElement(false, vrai, GameColor::ROUGE, false, pos, tex, rect)
{
}

Bouteille::Bouteille(bool vrai, GameColor c, Vector2f pos, Texture tex, IntRect rect) : PaintableElement(false, vrai, c, false, pos, tex, rect)
{
}
