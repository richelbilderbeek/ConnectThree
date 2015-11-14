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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "qtconnectthreemenudialog.h"

#include <cassert>

#include <QApplication>
#include <QDesktopWidget>

#include "connectthreemenudialog.h"
#include "qtaboutdialog.h"
#include "qtconnectthreegamedialog.h"
#include "qtconnectthreewidget.h"
#include "qtselectplayerwidget.h"
#include "testtimer.h"
#include "ui_qtconnectthreemenudialog.h"
#include "trace.h"
#pragma GCC diagnostic pop

ribi::con3::QtMenuDialog::QtMenuDialog(
  const Resources& resources,
  QWidget *parent
)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtConnectThreeMenuDialog),
    m_resources{resources},
    m_select{new QtSelectPlayerWidget}
{
  #ifndef NDEBUG
  Test();
  #endif

  ui->setupUi(this);
  assert(layout());

  layout()->addWidget(m_select);
}

ribi::con3::QtMenuDialog::~QtMenuDialog() noexcept
{
  delete ui;
  m_resources.RemoveFiles();
}


void ribi::con3::QtMenuDialog::on_button_start_clicked() noexcept
{
  QtGameDialog d(m_resources,this->m_select->GetIsPlayerHuman());
  d.setStyleSheet(this->styleSheet());
  d.setWindowIcon(this->windowIcon());
  this->ShowChild(&d);
}

void ribi::con3::QtMenuDialog::on_button_about_clicked() noexcept
{
  About about = MenuDialog().GetAbout();
  about.AddLibrary("QtConnectThreeWidget version: " + QtConnectThreeWidget::GetVersion());
  QtAboutDialog d(about);
  d.setStyleSheet(this->styleSheet());
  d.setWindowIcon(this->windowIcon());
  this->ShowChild(&d);
}

void ribi::con3::QtMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}

#ifndef NDEBUG
void ribi::con3::QtMenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {
    MenuDialog();
  }
  const Resources resources;
  QtGameDialog d(resources,std::bitset<3>(false));
  const TestTimer test_timer(__func__,__FILE__,1.0);
}
#endif
