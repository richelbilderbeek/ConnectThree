

#include "qtshowwinnerdialog.h"
#include <QKeyEvent>
#include "ui_qtshowwinnerdialog.h"


ribi::con3::QtShowWinnerDialog::QtShowWinnerDialog(
  const std::string& filename,
  const std::string& winner_text,
  QWidget *parent) noexcept
  : QDialog(parent),
    ui(new Ui::QtShowWinnerDialog)
{
  ui->setupUi(this);
  ui->label_image->setPixmap(QPixmap(filename.c_str()));
  ui->label_footer->setText(winner_text.c_str());
  ui->label_title->setText(winner_text.c_str());
  this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

ribi::con3::QtShowWinnerDialog::~QtShowWinnerDialog() noexcept
{
  delete ui;
}

void ribi::con3::QtShowWinnerDialog::keyPressEvent(QKeyEvent * e) noexcept
{
  if (e->key() == Qt::Key_Escape) { close(); return; }
}
