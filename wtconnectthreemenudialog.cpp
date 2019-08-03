#include <cassert>

#pragma GCC diagnostic push


#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <boost/bind.hpp>

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WImage>
#include <Wt/WLabel>
#include <Wt/WMenu>
#include <Wt/WStackedWidget>
#include <Wt/WTextArea>
#include <Wt/WPainter>

#include "about.h"
#include "connectthreeresources.h"
#include "connectthreemenudialog.h"
#include "wtaboutdialog.h"
#include "wtautoconfig.h"
#include "wtconnectthreegamedialog.h"
#include "wtconnectthreemenudialog.h"
#include "wtconnectthreewidget.h"
//#include "qtconnectthreeresources.h"
#include "wtconnectthreeselectplayerwidget.h"
#pragma GCC diagnostic pop

/*
ribi::con3::WtConnectThreeMenuDialog::WtConnectThreeMenuDialog()
  : ribi::con3::WtConnectThreeMenuDialog(ribi::con3::WtConnectThreeMenuDialog::CreateResources())
{

}
*/

ribi::con3::WtMenuDialog::WtMenuDialog(
    const Resources& resources
  )
  : m_game{},
    m_menu{},
    m_select(new WtSelectPlayerWidget(resources)),
    m_resources(resources)
{
  assert(m_select);
  this->setContentAlignment(Wt::AlignCenter);
  {
    Wt::WLabel * const title = new Wt::WLabel("ConnectThree");
    title->setStyleClass("title");
    this->addWidget(title);
  }
  this->addWidget(new Wt::WBreak);
  //Menu
  {
    Wt::WStackedWidget * const contents = new Wt::WStackedWidget;
    m_menu = new Wt::WMenu(contents,Wt::Horizontal);
    //Using CSS styleclass is the best (only?) way to display the menu well
    m_menu->setStyleClass("menu");
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Welcome",
        CreateNewWelcomeDialog());
      m_menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Select players",
        CreateNewSelectPlayersDialog());
      m_menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Start",
        CreateNewGameDialog());
      m_menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "About",
        CreateNewAboutDialog());
      m_menu->addItem(item);
    }
    //Display menu on top
    this->addWidget(m_menu);
    this->addWidget(new Wt::WBreak);
    //Display contents below menu
    this->addWidget(contents);
    m_menu->itemSelected().connect(
      this,&ribi::con3::WtMenuDialog::OnMenuItemChanged);
  }
  m_select->m_signal_on_clicked.connect(
    boost::bind(
      &ribi::con3::WtMenuDialog::OnSelectClicked,
      this));
}

ribi::WtAboutDialog * ribi::con3::WtMenuDialog::CreateNewAboutDialog()
{
  About a = MenuDialog().GetAbout();
  a.AddLibrary("WtConnectThreeWidget version: " + WtWidget::GetVersion());
  a.AddLibrary("WtAutoConfig version: " + WtAutoConfig::GetVersion());
  WtAboutDialog * const d = new WtAboutDialog(a,false);
  return d;
}

ribi::con3::WtGameDialog * ribi::con3::WtMenuDialog::CreateNewGameDialog()
{
  assert(m_select);
  m_game = new WtGameDialog(m_resources,m_select->GetIsPlayerHuman());
  assert(m_game);
  return m_game;
}

Wt::WWidget * ribi::con3::WtMenuDialog::CreateNewSelectPlayersDialog()
{
  Wt::WContainerWidget * dialog = new Wt::WContainerWidget;
  dialog->setContentAlignment(Wt::AlignCenter);
  dialog->addWidget(new Wt::WBreak);
  dialog->addWidget(m_select);
  return dialog;
}

Wt::WWidget * ribi::con3::WtMenuDialog::CreateNewWelcomeDialog() const
{
  Wt::WContainerWidget * dialog = new Wt::WContainerWidget;
  dialog->setContentAlignment(Wt::AlignCenter);
  dialog->addWidget(new Wt::WBreak);
  new Wt::WLabel("Welcome to ConnectThree",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("The goal of ConnectThree is to get three in a row horizontally or vertically:",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("Good #1",dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(new Wt::WImage(
    m_resources.GetInstructionsGoodFilenames()[0],"Good #1"));
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("Good #2",dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(new Wt::WImage(
    m_resources.GetInstructionsGoodFilenames()[1],"Good #2"));
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("Wrong",dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(new Wt::WImage(
    m_resources.
     GetInstructionsWrongFilename(),
     "Wrong"));
  return dialog;
}

void ribi::con3::WtMenuDialog::OnMenuItemChanged()
{
  if (m_menu->currentItem()->text() == "Start")
  {
    //This might reset the game
    if (m_game->HasWinner())
    {
      //Do nothing
    }
    else
    {
      //Game continues

      //Done by OnSelectClicked
      //m_game->SetIsPlayerHuman(m_select->GetIsPlayerHuman());
      m_game->StartTimer();
    }
  }
  else
  {
    m_game->PauseTimer();
  }
}

void ribi::con3::WtMenuDialog::OnSelectClicked()
{
  assert(m_game);
  if (m_game->HasWinner())
  {
    m_game->RestartGame();
    m_game->SetIsPlayerHuman(m_select->GetIsPlayerHuman());
  }
  else
  {
    assert(m_select);
    m_game->SetIsPlayerHuman(m_select->GetIsPlayerHuman());
  }
}

