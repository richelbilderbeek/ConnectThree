#ifndef QTSELECTPLAYERWIDGET_H
#define QTSELECTPLAYERWIDGET_H

#include <bitset>

#pragma GCC diagnostic push

#include <QImage>
#include <QWidget>
#pragma GCC diagnostic pop

namespace ribi {
namespace con3 {

class QtSelectPlayerWidget : public QWidget
{
  Q_OBJECT
public:
  explicit QtSelectPlayerWidget(QWidget *parent = 0);
  const std::bitset<3>& GetIsPlayerHuman() const { return m_is_player_human; }

protected:
  void mousePressEvent(QMouseEvent * e);
  void paintEvent(QPaintEvent *);


private:
  std::bitset<3> m_is_player_human;
  const QImage m_player1;
  const QImage m_player1_grey;
  const QImage m_player2;
  const QImage m_player2_grey;
  const QImage m_player3;
  const QImage m_player3_grey;
  const QImage m_computer1;
  const QImage m_computer2;
  const QImage m_computer3;
  const QImage m_computer_grey;
  static const int m_sprite_height;
  static const int m_sprite_width;
};

} //~namespace con3
} //~namespace ribi

#endif // QTSELECTPLAYERWIDGET_H
