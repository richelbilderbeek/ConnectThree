#ifndef QTCONNECTTHREEWIDGET_H
#define QTCONNECTTHREEWIDGET_H

#include <bitset>





#include <boost/signals2.hpp>
#include <QWidget>
#include "connectthreewidget.h" //thanks to MOC :-(


namespace ribi {
namespace con3 {

struct Resources;
struct ConnectThreeWidget;

class QtConnectThreeWidget : public QWidget
{
    Q_OBJECT
public:
  explicit QtConnectThreeWidget(
    const Resources& resources,
    QWidget *parent = 0,
    const std::bitset<3>& is_player_human = std::bitset<3>(true),
    const int n_cols = 16,
    const int n_rows = 12
  );

  void DoComputerTurn();
  Player GetActivePlayer() const noexcept;
  static std::string GetVersion() noexcept;
  static std::vector<std::string> GetVersionHistory() noexcept;
  Winner GetWinner() const noexcept;
  bool IsComputerTurn() const noexcept;

  ///m_signal_valid_move is emitted on a valid move,
  ///causing the game to be terminated or let
  ///the next player do his/her move.
  boost::signals2::signal<void ()> m_signal_valid_move;

signals:

public slots:

protected:
  void mousePressEvent(QMouseEvent * e) override final;
  void paintEvent(QPaintEvent *) override final;


  private:

  std::unique_ptr<ConnectThreeWidget> m_widget;
  const QImage m_player1;
  const QImage m_player2;
  const QImage m_player3;
  const QImage m_empty;
  const QImage& GetImage(const Square sprite) const noexcept;

  static const int m_sprite_width;
  static const int m_sprite_height;

};

} //~namespace con3
} //~namespace ribi


#endif // QTCONNECTTHREEWIDGET_H
