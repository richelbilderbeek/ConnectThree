#include "connectthreewidget.h"

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push

#include <boost/test/unit_test.hpp>

using namespace ribi;
using namespace ribi::con3;

BOOST_AUTO_TEST_CASE(play_one_game)
{
  ConnectThreeWidget widget;
  assert(widget.IsHuman(Player::player1));
  assert(widget.IsHuman(Player::player2));
  assert(widget.IsHuman(Player::player3));
  assert(widget.GetGame().GetCols() == 16);
  assert(widget.GetGame().GetRows() == 12);
  while (widget.GetGame().GetWinner() == Winner::no_winner)
  {
    switch ((std::rand() >> 4) % 5)
    {
      case 0: widget.OnKeyPress(ConnectThreeWidget::Key::up); break;
      case 1: widget.OnKeyPress(ConnectThreeWidget::Key::right); break;
      case 2: widget.OnKeyPress(ConnectThreeWidget::Key::down); break;
      case 3: widget.OnKeyPress(ConnectThreeWidget::Key::left); break;
      case 4: widget.OnKeyPress(ConnectThreeWidget::Key::select); break;
    }
  }
}

#pragma GCC diagnostic pop

