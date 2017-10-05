#ifndef WTSELECTPLAYERWIDGET_H
#define WTSELECTPLAYERWIDGET_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <boost/signals2.hpp>

#include <Wt/WPaintedWidget>
#pragma GCC diagnostic pop

namespace Wt
{
  struct WImage;
  #ifndef WPAINTER_H_
  struct WPainter { struct Image; };
  #endif
}

#include "connectthreeresources.h"
#include "connectthreefwd.h"

namespace ribi {
namespace con3 {

struct WtSelectPlayerWidget : public Wt::WPaintedWidget
{
  explicit WtSelectPlayerWidget(
    const Resources& resources
  );
  WtSelectPlayerWidget(const WtSelectPlayerWidget&) = delete;
  WtSelectPlayerWidget& operator=(const WtSelectPlayerWidget&) = delete;
  ~WtSelectPlayerWidget() noexcept;

  const std::bitset<3>& GetIsPlayerHuman() const { return m_is_player_human; }
  boost::signals2::signal<void ()> m_signal_on_clicked;

  private:
  void OnClick(const Wt::WMouseEvent& e);
  void paintEvent(Wt::WPaintDevice *paintDevice);

  const Wt::WPainter::Image * m_computer_grey;
  const std::vector<const Wt::WPainter::Image *> m_computers;
  std::bitset<3> m_is_player_human;
  const std::vector<const Wt::WPainter::Image *> m_players;
  const std::vector<const Wt::WPainter::Image *> m_players_grey;
};

} //~namespace con3
} //~namespace ribi

#endif // WTSELECTPLAYERWIDGET_H
