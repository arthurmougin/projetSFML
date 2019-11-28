#include "spike.h"

spike::spike():GameEntity()
{
}

spike::spike(Vector2f pos, Texture tex, IntRect rect) : GameEntity(true, pos, tex, rect)
{
}
