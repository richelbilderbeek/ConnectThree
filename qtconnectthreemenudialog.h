#ifndef QTCONNECTTHREEMENUDIALOG_H
#define QTCONNECTTHREEMENUDIALOG_H

#include <string>
#include <vector>
#include "connectthreeresources.h"
#include <QDialog>

namespace Ui {
  class QtConnectThreeMenuDialog;
}

namespace ribi {
namespace con3 {

struct QtSelectPlayerWidget;

class QtMenuDialog : public QDialog
{
  Q_OBJECT

public:
  ///Throws an exception if the resources cannot be found
  explicit QtMenuDialog(
    const Resources& resources,
    QWidget *parent = 0
  );
  QtMenuDialog(const QtMenuDialog&) = delete;
  QtMenuDialog& operator=(const QtMenuDialog&) = delete;
  ~QtMenuDialog() noexcept;

private:
  Ui::QtConnectThreeMenuDialog *ui;
  const Resources& m_resources;
  QtSelectPlayerWidget * m_select; //Management handled by QDialog

private slots:

  void on_button_start_clicked() noexcept;
  void on_button_about_clicked() noexcept;
  void on_button_quit_clicked() noexcept;
};

} //~namespace con3
} //~namespace ribi

#endif // QTCONNECTTHREEMENUDIALOG_H
