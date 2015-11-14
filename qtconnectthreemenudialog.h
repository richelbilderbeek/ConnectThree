//---------------------------------------------------------------------------
/*
GameConnectThree, connect-three game
Copyright (C) 2010-2015 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/GameConnectThree.htm
//---------------------------------------------------------------------------
#ifndef QTCONNECTTHREEMENUDIALOG_H
#define QTCONNECTTHREEMENUDIALOG_H

#include <string>
#include <vector>
#include "connectthreeresources.h"
#include "qthideandshowdialog.h"

namespace Ui {
  class QtConnectThreeMenuDialog;
}

namespace ribi {
namespace con3 {

struct QtSelectPlayerWidget;

class QtMenuDialog : public QtHideAndShowDialog
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

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

} //~namespace con3
} //~namespace ribi

#endif // QTCONNECTTHREEMENUDIALOG_H
