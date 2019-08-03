#ifndef WTCONNECTTHREEMENUDIALOG_H
#define WTCONNECTTHREEMENUDIALOG_H

#pragma GCC diagnostic push


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
