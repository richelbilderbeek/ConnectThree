//---------------------------------------------------------------------------
/*
GameConnectThree, connect-three game
Copyright (C) 2010-2016 Richel Bilderbeek

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
#ifndef WTCONNECTTHREEMENUDIALOG_H
#define WTCONNECTTHREEMENUDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <boost/scoped_ptr.hpp>
#include <boost/signals2.hpp>

#include <Wt/WContainerWidget>

#include "connectthreeresources.h"
#include "connectthreefwd.h"
#pragma GCC diagnostic pop

namespace Wt
{
  struct WMenu;
  struct WWidget;
}

namespace ribi {

struct WtAboutDialog;

namespace con3 {

struct WtMenuDialog : public Wt::WContainerWidget
{
  //WtConnectThreeMenuDialog();
  WtMenuDialog(
    const Resources& resources
  );
  WtMenuDialog(const WtMenuDialog&) = delete;
  WtMenuDialog& operator=(const WtMenuDialog&) = delete;

  private:
  WtGameDialog * m_game;
  Wt::WMenu * m_menu;
  WtSelectPlayerWidget * m_select;

  WtGameDialog * CreateNewGameDialog();
  Wt::WWidget * CreateNewWelcomeDialog() const;
  Wt::WWidget * CreateNewSelectPlayersDialog();
  void OnMenuItemChanged();
  void OnSelectClicked();
  public:
  static WtAboutDialog * CreateNewAboutDialog();
  const Resources m_resources;
};

} //~namespace con3
} //~namespace ribi

#endif // WTCONNECTTHREEMENUDIALOG_H
