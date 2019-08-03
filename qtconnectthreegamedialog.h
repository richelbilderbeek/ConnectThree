#ifndef QTCONNECTTHREEGAMEDIALOG_H
#define QTCONNECTTHREEGAMEDIALOG_H

#include <bitset>




#include <QDialog>



namespace Ui {
  class QtConnectThreeGameDialog;
}

namespace ribi {
namespace con3 {

struct QtConnectThreeWidget;
struct Resources;

class QtGameDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtGameDialog(
    const Resources& resources,
    const std::bitset<3>& is_player_human = std::bitset<3>(true),
    QWidget *parent = nullptr
  ) noexcept;
  QtGameDialog(const QtGameDialog&) = delete;
  QtGameDialog& operator=(const QtGameDialog&) = delete;
  ~QtGameDialog() noexcept;

public slots:
  void DoComputerTurn() noexcept;

private:
  Ui::QtConnectThreeGameDialog *ui;
  QtConnectThreeWidget * const m_board;
  const std::bitset<3>& m_is_player_human;

  ///The filenames
  const Resources& m_resources;

  ///OnValidMove is called after a valid move. The game
  ///is either terminated, or the next player can do
  ///his/her move.
  void OnValidMove() noexcept;
};

} //~namespace con3
} //~namespace ribi

#endif // QTCONNECTTHREEGAMEDIALOG_H
