#ifndef CONNECTTHREEWIDGET_H
#define CONNECTTHREEWIDGET_H

#include <bitset>
#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/tuple/tuple.hpp>

#include "connectthreegame.h"
#include "connectthreefwd.h"
#pragma GCC diagnostic pop

namespace ribi {

struct TextCanvas;

namespace con3 {

struct Game;

///ConnectThreeWidget embodies the interaction with a user
///It keeps track which players are human and whose turn it is
struct ConnectThreeWidget
{
  enum class Key { up, right, down, left, select };

  explicit ConnectThreeWidget(
    const std::bitset<3>& is_player_human = CreateDefaultIsPlayerHuman(),
    const int n_cols = 16,
    const int n_rows = 12);


  bool CanDoMove() const noexcept { return CanDoMove(m_x,m_y); }
  bool CanSelect(const int x, const int y) const noexcept;

  static std::bitset<3> CreateDefaultIsPlayerHuman() noexcept;

  ///Let the computer do a move
  void DoComputerMove() noexcept;

  ///Press select at the current place
  void DoMove() noexcept;


  const Game& GetGame() const noexcept { return m_game; }
  const std::bitset<3>& GetIsPlayerHuman() const noexcept { return m_is_player_human; }
  static std::string GetVersion() noexcept;
  static std::vector<std::string> GetVersionHistory() noexcept;
  bool IsComputerTurn() const noexcept;
  bool IsHuman(const Player player) const noexcept;
  void OnKeyPress(const Key key) noexcept;
  void Restart() noexcept;
  void Select(const int x, const int y) noexcept;
  void SetIsPlayerHuman(const std::bitset<3>& is_player_human) noexcept;

  ///Will throw std::logic_error when there is no move
  Move SuggestMove() const;
  void Tick() noexcept;

  private:

  Game m_game;
  std::bitset<3> m_is_player_human;

  //X coordinat of cursor
  int m_x;

  //Y coordinat of cursor
  int m_y;

  bool CanDoMove(const int x, const int y) const noexcept;
  void DoMove(const int x, const int y) noexcept;
  int PlayerToIndex(const Player player) const noexcept;

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

} //~namespace con3
} //~namespace ribi

#endif // CONNECTTHREEWIDGET_H
