



#include "wtconnectthreewidget.h"

#include <cassert>

#include <Wt/WPaintDevice>
#include <Wt/WPainter>
#include <Wt/WTimer>

#include "connectthreewidget.h"
#include "connectthreeresources.h"
#include "connectthreemove.h"


///Yes, naming the filename twice feels dumb, but
///I could not find enough documentation about
///how I should use the Wt::WPainter::Image constructor
ribi::con3::WtWidget::WtWidget(
  const Resources& resources,
  const std::bitset<3>& is_player_human,
  const int n_cols,
  const int n_rows)
  : m_signal_valid_move{},
    m_widget(new con3::ConnectThreeWidget(is_player_human,n_cols,n_rows)),
    m_players(
      {
        boost::shared_ptr<const Wt::WPainter::Image>(
          new Wt::WPainter::Image(
            resources.GetPlayersFilenames()[0],
            resources.GetPlayersFilenames()[0])),
        boost::shared_ptr<const Wt::WPainter::Image>(
          new Wt::WPainter::Image(
            resources.GetPlayersFilenames()[1],
            resources.GetPlayersFilenames()[1])),
        boost::shared_ptr<const Wt::WPainter::Image>(
          new Wt::WPainter::Image(
            resources.GetPlayersFilenames()[2],
            resources.GetPlayersFilenames()[2])),
      }
    ),
    m_empty(new Wt::WPainter::Image(
      resources.GetEmptyFilename(),
      resources.GetEmptyFilename())),
    m_timer(new Wt::WTimer)
{
  const int sprite_width  = m_empty->width();
  const int sprite_height = m_empty->height();

  this->resize(n_cols * sprite_width,n_rows * sprite_height);
  this->mouseWentDown().connect(this, &ribi::con3::WtWidget::OnClick);
  this->update();
  m_timer->setInterval(100);
  m_timer->timeout().connect(
    boost::bind(
      &ConnectThreeWidget::Tick,
      m_widget.get()));
}

void ribi::con3::WtWidget::DoComputerTurn()
{
  assert(IsComputerTurn());
  const auto move = m_widget->SuggestMove();
  //Check for draw
  assert(m_widget->CanSelect(move.GetX(),move.GetY()));
  m_widget->Select(move.GetX(),move.GetY());
  m_widget->DoMove();
  this->update();
}

ribi::con3::Player ribi::con3::WtWidget::GetActivePlayer() const
{
  return m_widget->GetGame().GetActivePlayer();
}

const std::bitset<3>& ribi::con3::WtWidget::GetIsPlayerHuman() const
{
  return m_widget->GetIsPlayerHuman();
}

std::string ribi::con3::WtWidget::GetVersion()
{
  return "3.0";
}

std::vector<std::string> ribi::con3::WtWidget::GetVersionHistory()
{
  return {
    "2011-01-08: version 1.0: initial version",
    "2011-01-10: version 1.1: added use of Resources",
    "2011-04-22: version 2.0: added Restart, SetIsPlayerHuman methods and a different way of resource acquisition",
    "2014-02-17: version 2.1: put in namespace con3, use of enum classes",
    "2015-01-09: version 3.0: moved to own GitHub",
  };
}

ribi::con3::Winner ribi::con3::WtWidget::GetWinner() const
{
  assert(m_widget);
  return m_widget->GetGame().GetWinner();
}

bool ribi::con3::WtWidget::IsComputerTurn() const
{
  assert(m_widget);
  return m_widget->IsComputerTurn();
}

void ribi::con3::WtWidget::OnClick(const Wt::WMouseEvent& e)
{
  //Disable clicking if it's the AI's turn
  if (IsComputerTurn()) return;

  const int sprite_width  = m_empty->width();
  const int sprite_height = m_empty->height();

  const int mouse_x = e.widget().x;
  const int mouse_y = e.widget().y;
  const int x = mouse_x / sprite_width;
  const int y = mouse_y / sprite_height;
  if (m_widget->GetGame().CanDoMove(x,y))
  {
    assert(m_widget->CanSelect(x,y));
    m_widget->Select(x,y);
    m_widget->DoMove();
    this->update();
    m_signal_valid_move();
  }
}

void ribi::con3::WtWidget::paintEvent(Wt::WPaintDevice *paintDevice)
{
  Wt::WPainter painter(paintDevice);
  assert(m_widget);
  const int sprite_width  = m_empty->width();
  const int sprite_height = m_empty->height();
  const int n_rows = m_widget->GetGame().GetRows();
  const int n_cols = m_widget->GetGame().GetCols();
  for (int y = 0; y!=n_rows; ++y)
  {
    for (int x = 0; x!=n_cols; ++x)
    {
      painter.drawImage(
        x * sprite_width,
        y * sprite_height,
        GetImage(m_widget->GetGame().GetSquare(x,y)));
    }
  }
}

const Wt::WPainter::Image& ribi::con3::WtWidget::GetImage(const Square sprite) const
{
  switch (sprite)
  {
    case Square::empty  : return *m_empty.get();
    case Square::player1: return *m_players[0].get();
    case Square::player2: return *m_players[1].get();
    case Square::player3: return *m_players[2].get();
    default:
      assert(!"Should not get here");
      throw std::logic_error("Unknown ribi::con3::WtConnectThreeWidget::GetImage value");
  }
}

void ribi::con3::WtWidget::Restart()
{
  assert(m_widget);
  m_widget->Restart();
  this->update();
}

void ribi::con3::WtWidget::SetIsPlayerHuman(const std::bitset<3>& is_player_human)
{
  assert(m_widget);
  m_widget->SetIsPlayerHuman(is_player_human);
}
