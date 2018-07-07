#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "qtconnectthreegamedialog.h"

#include <QDesktopWidget>
#include <QTimer>

#include "connectthreegame.h"
#include "connectthreewidget.h"
#include "connectthreeresources.h"
#include "ui_qtconnectthreegamedialog.h"
#include "qtconnectthreegamedialog.h"
#include "qtconnectthreewidget.h"
#include "qtshowwinnerdialog.h"
#pragma GCC diagnostic pop

ribi::con3::QtGameDialog::QtGameDialog(
  const Resources& resources,
  const std::bitset<3>& is_player_human,
  QWidget *parent
) noexcept
  : QDialog(parent),
    ui(new Ui::QtConnectThreeGameDialog),
    m_board{
      new QtConnectThreeWidget(
        resources,
        this,
        is_player_human,16,8),
    },
    m_is_player_human(is_player_human),
    m_resources(resources)
{
  ui->setupUi(this);

  //Add board widget
  {
    assert(!ui->widget->layout());
    QLayout * const mylayout = new QVBoxLayout;
    mylayout->addWidget(m_board);
    ui->widget->setLayout(mylayout);
  }

  //Qt5
  //QObject::connect(ui->button_quit,&QPushButton::clicked,this,&ribi::con3::QtGameDialog::close);
  //QObject::connect(ui->button_quit,SIGNAL(clicked(bool)),this,SLOT(close()));

  QObject::connect(ui->button_quit,SIGNAL(clicked()),this,SLOT(close()));
  m_board->m_signal_valid_move.connect(boost::bind(&ribi::con3::QtGameDialog::OnValidMove,this));

  //Put the dialog in the screen center
  const QRect screen = QApplication::desktop()->screenGeometry();
  this->move( screen.center() - this->rect().center() );

  ui->button_quit->setText(resources.GetQuitText().c_str());

  OnValidMove(); //Draw screen
}

ribi::con3::QtGameDialog::~QtGameDialog() noexcept
{
  delete m_board;
  delete ui;
}

void ribi::con3::QtGameDialog::DoComputerTurn() noexcept
{
  this->m_board->DoComputerTurn();
  OnValidMove();
}

void ribi::con3::QtGameDialog::OnValidMove() noexcept
{
  if (m_board->GetWinner() == Winner::no_winner)
  {
    const Player active_player = m_board->GetActivePlayer();
    switch(active_player)
    {
      case Player::player1:
        ui->label_player1->setPixmap(QPixmap(m_resources.GetPlayersFilenames()[0].c_str()));
        ui->label_player2->setPixmap(QPixmap(m_resources.GetPlayersGreyFilenames()[1].c_str()));
        ui->label_player3->setPixmap(QPixmap(m_resources.GetPlayersGreyFilenames()[2].c_str()));
        break;
      case Player::player2:
        ui->label_player1->setPixmap(QPixmap(m_resources.GetPlayersGreyFilenames()[0].c_str()));
        ui->label_player2->setPixmap(QPixmap(m_resources.GetPlayersFilenames()[1].c_str()));
        ui->label_player3->setPixmap(QPixmap(m_resources.GetPlayersGreyFilenames()[2].c_str()));
        break;
      case Player::player3:
        ui->label_player1->setPixmap(QPixmap(m_resources.GetPlayersGreyFilenames()[0].c_str()));
        ui->label_player2->setPixmap(QPixmap(m_resources.GetPlayersGreyFilenames()[1].c_str()));
        ui->label_player3->setPixmap(QPixmap(m_resources.GetPlayersFilenames()[2].c_str()));
        break;
      default:
        assert(!"Should not get here");
    }
    if (this->m_board->IsComputerTurn())
    {
      //Do a computer turn after a second
      QTimer::singleShot(100,
        this,
        //&ribi::con3::QtConnectThreeGameDialog::DoComputerTurn //Does not work
        SLOT(DoComputerTurn())
      );
    }

    return;
  }
  //There is a winner, or the screen is full
  {
    std::string filename;
    switch(m_board->GetWinner())
    {
        case Winner::player1  : filename = m_resources.GetPlayersFilenames()[0]; break;
        case Winner::player2  : filename = m_resources.GetPlayersFilenames()[1]; break;
        case Winner::player3  : filename = m_resources.GetPlayersFilenames()[2]; break;
        case Winner::no_winner: filename = m_resources.GetEmptyFilename(); break;
        case Winner::draw     : filename = m_resources.GetEmptyFilename(); break;
        default:
          assert("should not get here");
    }
    QtShowWinnerDialog d(filename,m_resources.GetWinnerText());
    d.setStyleSheet(this->styleSheet());
    d.setWindowIcon(this->windowIcon());

    //this->hide();
    d.exec();
  }
  this->close();
}
