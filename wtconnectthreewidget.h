#ifndef WTCONNECTTHREEWIDGET_H
#define WTCONNECTTHREEWIDGET_H

#include <bitset>
#include <string>
#include <vector>

#pragma GCC diagnostic push



#include <boost/shared_ptr.hpp>
#include <boost/signals2.hpp>

#include <Wt/WPaintedWidget>
#include <Wt/WPainter>
#include "connectthreefwd.h"
#include "connectthreeplayer.h"
#include "connectthreesquare.h"
#include "connectthreewinner.h"
#include "connectthreeresources.h"
#pragma GCC diagnostic pop

namespace Wt
{
  struct WPaintDevice;
  struct WTimer;
}

namespace ribi {
namespace con3 {

//struct ConnectThreeWidget;
//struct Resources;

///WtConnectThreeWidget is a Wt widget to display
///the area/board of the ConnectThree class.
struct WtWidget : public Wt::WPaintedWidget
{
  explicit WtWidget(
    const Resources& resources,
    const std::bitset<3>& is_player_human = std::bitset<3>(true),
    const int n_cols = 16,
    const int n_rows = 12
  );

  void DoComputerTurn();
  Player GetActivePlayer() const;
  const std::bitset<3>& GetIsPlayerHuman() const;
  static std::string GetVersion();
  static std::vector<std::string> GetVersionHistory();
  Winner GetWinner() const;
  bool IsComputerTurn() const;
  void Restart();
  void SetIsPlayerHuman(const std::bitset<3>& is_player_human);

  ///m_signal_valid_move is emitted on a valid move,
  ///causing the game to be terminated or let
  ///the next player do his/her move.
  boost::signals2::signal<void ()> m_signal_valid_move;

  private:
  void OnClick(const Wt::WMouseEvent& e);
  void paintEvent(Wt::WPaintDevice *paintDevice);

  const boost::scoped_ptr<ConnectThreeWidget> m_widget;
  const std::vector<boost::shared_ptr<const Wt::WPainter::Image> > m_players;
  const boost::scoped_ptr<const Wt::WPainter::Image> m_empty;
  const boost::scoped_ptr<Wt::WTimer> m_timer;
  const Wt::WPainter::Image& GetImage(const Square sprite) const;
};

} //~namespace con3
} //~namespace ribi

#endif // WTCONNECTTHREEWIDGET_H
