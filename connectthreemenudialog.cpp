

#include "connectthreemenudialog.h"


#include "connectthreegame.h"
#include "connectthreewidget.h"
#include "connectthreemove.h"

#include <cassert>
#include <iostream>



int ribi::con3::MenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc != 1)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }

  Game c(15,5);
  const std::bitset<3> is_player_human(0);
  while (c.GetWinner() == Winner::no_winner)
  {
    c.DoMove(c.SuggestMove(is_player_human));
    std::cout << c
      << std::endl
      << std::endl;
  }

  switch (c.GetWinner())
  {
    case Winner::player1  : std::cout << "Player 1 won the game"; break;
    case Winner::player2  : std::cout << "Player 2 won the game"; break;
    case Winner::player3  : std::cout << "Player 3 won the game"; break;
    case Winner::draw     : std::cout << "The game ended in a draw"; break;
    case Winner::no_winner:
      assert(!"Should not get here");
  }

  std::cout << std::endl;

  return 0;
}

ribi::About ribi::con3::MenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "ConnectThree",
    "connect-three game",
    "the 14th of November 2015",
    "2010-2016",
    "http://www.richelbilderbeek.nl/GameConnectThree.htm",
    GetVersion(),
    GetVersionHistory()
  );
  a.AddLibrary("ConnectThree version: " + Game::GetVersion());
  a.AddLibrary("ConnectThreeWidget version: " + ConnectThreeWidget::GetVersion());
  a.AddLibrary("Special thanks to Mark Wiering for his excellent bug reports");
  return a;
}

ribi::Help ribi::con3::MenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}

std::string ribi::con3::MenuDialog::GetVersion() const noexcept
{
  return "7.1";
}

std::vector<std::string> ribi::con3::MenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2007-xx-xx: version 1.0: initial version as part of K3OpEenRij",
    "2011-01-10: version 5.0: initial Qt4 version",
    "2011-01-11: version 5.2: support that the game can end in a draw",
    "2011-04-22: version 6.0: major architectural changes",
    "2011-04-24: version 6.1: fixed a bug that showed when deploying to my WtWebsite",
    "2011-04-25: version 6.2: hopefully fixed the bug as in 6.1, fixed desktop version",
    "2013-07-11: version 6.3: transitioned to Qt5 and Boost 1.54.0",
    "2013-07-21: version 6.4: improved looks",
    "2013-08-06: version 6.5: facilitate K3OpEenRij using ConnectThree classes",
    "2014-01-23: version 6.6: command-line version displays a game",
    "2015-11-14: version 7.0: moved to own GitHub",
    "2016-01-09: version 7.1: web application also works again",
  };
}
