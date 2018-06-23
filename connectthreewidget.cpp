#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "connectthreewidget.h"
#pragma GCC diagnostic pop

#include <cassert>
#include <stdexcept>

#include "connectthreegame.h"
#include "connectthreemove.h"

ribi::con3::ConnectThreeWidget::ConnectThreeWidget(
  const std::bitset<3>& is_player_human,
  const int n_cols,
  const int n_rows)
  : m_game(n_cols,n_rows),
    m_is_player_human(is_player_human),
    m_x{n_cols / 2},
    m_y{n_rows / 2}
{
  assert(m_x >= 0);
  assert(m_y >= 0);
  assert(n_cols > 0);
  assert(n_rows > 0);
  assert(m_x < n_cols);
  assert(m_y < n_rows);
}

bool ribi::con3::ConnectThreeWidget::CanDoMove(const int x,const int y) const noexcept
{
  return m_game.CanDoMove(x,y);
}

bool ribi::con3::ConnectThreeWidget::CanSelect(const int x, const int y) const noexcept
{
  return
       x >= 0 && x < GetGame().GetCols()
    && y >= 0 && y < GetGame().GetRows()
    && GetGame().GetSquare(x,y) == Square::empty;
}

std::bitset<3> ribi::con3::ConnectThreeWidget::CreateDefaultIsPlayerHuman() noexcept
{
  std::bitset<3> b;
  b[0] = true;
  b[1] = true;
  b[2] = true;
  return b;
}

void ribi::con3::ConnectThreeWidget::DoComputerMove() noexcept
{
  const auto move = SuggestMove();
  assert(CanDoMove(move.GetX(),move.GetY()));
  DoMove(move.GetX(),move.GetY());
}

void ribi::con3::ConnectThreeWidget::DoMove() noexcept
{
  assert(CanDoMove());
  assert(CanDoMove(m_x,m_y));
  m_game.DoMove(m_x,m_y);
}

void ribi::con3::ConnectThreeWidget::DoMove(const int x,const int y) noexcept
{
  assert(CanDoMove(x,y));
  m_game.DoMove(x,y);
}

std::string ribi::con3::ConnectThreeWidget::GetVersion() noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::con3::ConnectThreeWidget::GetVersionHistory() noexcept
{
  return {
    "2011-04-20: version 1.0: initial version"
    "2015-11-14: version 1.1: simplified"
  };
}

bool ribi::con3::ConnectThreeWidget::IsComputerTurn() const noexcept
{
  return !IsHuman(m_game.GetActivePlayer());
}

bool ribi::con3::ConnectThreeWidget::IsHuman(const Player player) const noexcept
{
  const int player_index{PlayerToIndex(player)};
  assert(player_index >= 0);
  assert(player_index < static_cast<int>(m_is_player_human.size()));
  return m_is_player_human[player_index];
}

void ribi::con3::ConnectThreeWidget::OnKeyPress(const Key key) noexcept
{
  assert(m_x >= 0);
  assert(m_y >= 0);
  assert(m_x < m_game.GetCols());
  assert(m_y < m_game.GetRows());

  switch (key)
  {
    case Key::up   : if (m_y > 0) --m_y; break;
    case Key::right: if (m_x + 1 < m_game.GetCols()) ++m_x; break;
    case Key::down : if (m_y + 1 < m_game.GetRows()) ++m_y; break;
    case Key::left : if (m_x > 0) --m_x; break;
    case Key::select:
      if (m_game.CanDoMove(m_x,m_y)) { m_game.DoMove(m_x,m_y); }
      break;
  }

  assert(m_x >= 0);
  assert(m_y >= 0);
  assert(m_x < m_game.GetCols());
  assert(m_y < m_game.GetRows());
}

int ribi::con3::ConnectThreeWidget::PlayerToIndex(const Player player) const noexcept
{
  switch(player)
  {
    case Player::player1: return 0;
    case Player::player2: return 1;
    case Player::player3: return 2;
    default:
      assert(!"Should not get here");
  }
  return 0;
}

void ribi::con3::ConnectThreeWidget::Restart() noexcept
{
  m_game.Restart();
}

void ribi::con3::ConnectThreeWidget::Select(const int x, const int y) noexcept
{
  assert(CanSelect(x,y));
  m_x = x;
  m_y = y;
}

void ribi::con3::ConnectThreeWidget::SetIsPlayerHuman(const std::bitset<3>& is_player_human) noexcept
{
  if (m_is_player_human != is_player_human)
  {
    //Only restart game if something changed
    m_is_player_human = is_player_human;
    Restart();
  }
}

ribi::con3::Move ribi::con3::ConnectThreeWidget::SuggestMove() const
{
  return m_game.SuggestMove(m_is_player_human);
}

///Tick does either wait for a human to make his/her move
///or lets a computer do its move. Tick must be called by
///external timers like Wt::WTimer or QTimer.
void ribi::con3::ConnectThreeWidget::Tick() noexcept
{
  if (IsComputerTurn())
  {
    const auto m = m_game.SuggestMove(m_is_player_human);
    m_game.DoMove(m);
  }
}
