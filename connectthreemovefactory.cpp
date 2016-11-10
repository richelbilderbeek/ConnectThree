#include "connectthreemovefactory.h"

#include <cassert>
#include "connectthreemove.h"

ribi::con3::Move ribi::con3::MoveFactory::Create(
  const int x, const int y, const Player player) const noexcept
{
  const Move move {
    x,y,player
  };
  return move;
}
