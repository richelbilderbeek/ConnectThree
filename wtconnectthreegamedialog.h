#ifndef WTCONNECTTHREEGAMEDIALOG_H
#define WTCONNECTTHREEGAMEDIALOG_H

#include <bitset>
#include <vector>

#pragma GCC diagnostic push


#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <boost/signals2.hpp>
#include <Wt/WContainerWidget>
#include "connectthreeresources.h"
#include "connectthreefwd.h"
#pragma GCC diagnostic pop

namespace Wt
{
  struct WTimer;
}


namespace ribi {
namespace con3 {

///WtConnectThreeGameDialog contains the
///ConnectThree game.
struct WtGameDialog : public Wt::WContainerWidget
{
  enum State { state_playing, state_winner };
  explicit WtGameDialog(
    const Resources& resources,
    const std::bitset<3>& is_player_human = std::bitset<3>(true)
  );
  WtGameDialog(const WtGameDialog&) = delete;
  WtGameDialog& operator=(const WtGameDialog&) = delete;
  bool HasWinner() const { return m_state == state_winner; }
  void PauseTimer();
  void RestartGame();
  void SetIsPlayerHuman(const std::bitset<3>& is_player_human);
  void StartTimer();

  private:
  ~WtGameDialog();
  WtWidget * m_board;
  std::bitset<3> m_is_player_human;
  std::vector<Wt::WImage *> m_players;
  const Resources& m_resources;
  State m_state;
  Wt::WTimer * const m_timer;

  void DoComputerTurn();
  void OnValidMove();
  void ShowGame();
  void ShowWinner();
  void UpdatePlayersPanel();
};

} //~namespace con3
} //~namespace ribi

#endif // WTCONNECTTHREEGAMEDIALOG_H
