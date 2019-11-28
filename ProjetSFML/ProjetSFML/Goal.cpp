#include "Goal.h"

Goal::Goal():GameEntity()
{
}

Goal::Goal(Vector2f pos, Texture tex, IntRect rect) : GameEntity(true, 4, pos, tex, rect)
{
}
