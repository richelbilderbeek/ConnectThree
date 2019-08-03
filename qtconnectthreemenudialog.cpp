



#include "qtconnectthreemenudialog.h"

#include <cassert>

#include <QApplication>
#include <QDesktopWidget>

#include "connectthreemenudialog.h"
#include "qtaboutdialog.h"
#include "qtconnectthreegamedialog.h"
#include "qtconnectthreewidget.h"
#include "qtselectplayerwidget.h"
#include "ui_qtconnectthreemenudialog.h"


ribi::con3::QtMenuDialog::QtMenuDialog(
  const Resources& resources,
  QWidget *parent
)
  : QDialog(parent),
    ui(new Ui::QtConnectThreeMenuDialog),
    m_resources(resources),
    m_select{new QtSelectPlayerWidget}
{
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
  //this->ShowChild(&d);
  d.exec();
}

void ribi::con3::QtMenuDialog::on_button_about_clicked() noexcept
{
  About about = MenuDialog().GetAbout();
  about.AddLibrary("QtConnectThreeWidget version: " + QtConnectThreeWidget::GetVersion());
  QtAboutDialog d(about);
  d.setStyleSheet(this->styleSheet());
  d.setWindowIcon(this->windowIcon());
  d.exec();
}

void ribi::con3::QtMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}
