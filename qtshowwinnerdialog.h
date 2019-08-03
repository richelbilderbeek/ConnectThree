#ifndef QTSHOWWINNERDIALOG_H
#define QTSHOWWINNERDIALOG_H

#include <string>





#include <QDialog>


namespace Ui {
  class QtShowWinnerDialog;
}

namespace ribi {
namespace con3 {

class QtShowWinnerDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtShowWinnerDialog(
    const std::string& filename,
    const std::string& winner_text,
    QWidget *parent = 0
  ) noexcept;
  QtShowWinnerDialog(const QtShowWinnerDialog&) = delete;
  QtShowWinnerDialog& operator=(const QtShowWinnerDialog&) = delete;
  ~QtShowWinnerDialog() noexcept;

protected:
  void keyPressEvent(QKeyEvent *) noexcept;

private:
  Ui::QtShowWinnerDialog *ui;
};

} //~namespace con3
} //~namespace ribi

#endif // QTSHOWWINNERDIALOG_H
