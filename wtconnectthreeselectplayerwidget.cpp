#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <Wt/WImage>
#include <Wt/WPainter>

#include "wtconnectthreeselectplayerwidget.h"

#include <cassert>
#pragma GCC diagnostic pop

///Yes, naming the filename twice feels dumb, but
///I could not find enough documentation about
///how I should use the Wt::WPainter::Image constructor
ribi::con3::WtSelectPlayerWidget::WtSelectPlayerWidget(
  const Resources& resources)
  : m_signal_on_clicked{},
    m_computer_grey(new Wt::WPainter::Image(
      resources.GetComputerGreyFilename(),
      resources.GetComputerGreyFilename())
      ),
    m_computers(
    {
      new Wt::WPainter::Image(
        resources.GetComputersFilenames()[0],
        resources.GetComputersFilenames()[0]
        ),
      new Wt::WPainter::Image(
        resources.GetComputersFilenames()[1],
        resources.GetComputersFilenames()[1]
        ),
      new Wt::WPainter::Image(
        resources.GetComputersFilenames()[2],
        resources.GetComputersFilenames()[2]
        )
    } ),
    m_is_player_human{},
    m_players(
    {
      new Wt::WPainter::Image(
        resources.GetPlayersFilenames()[0],
        resources.GetPlayersFilenames()[0]),
      new Wt::WPainter::Image(
        resources.GetPlayersFilenames()[1],
        resources.GetPlayersFilenames()[1]),
      new Wt::WPainter::Image(
        resources.GetPlayersFilenames()[2],
        resources.GetPlayersFilenames()[2])
    } ),
    m_players_grey(
    {
      new Wt::WPainter::Image(
        resources.GetPlayersGreyFilenames()[0],
        resources.GetPlayersGreyFilenames()[0]),
      new Wt::WPainter::Image(
        resources.GetPlayersGreyFilenames()[1],
        resources.GetPlayersGreyFilenames()[1]),
      new Wt::WPainter::Image(
        resources.GetPlayersGreyFilenames()[2],
        resources.GetPlayersGreyFilenames()[2])
    } )
{
  m_is_player_human[0] = true;
  m_is_player_human[1] = true;
  m_is_player_human[2] = true;

  assert(m_computers.size() == 3);
  assert(m_players.size() == 3);
  assert(m_players_grey.size() == 3);
  for (int i=0; i!=3; ++i)
  {
    assert(m_computers[i]);
    assert(m_players[i]);
    assert(m_players_grey[i]);
  }
  assert(m_computer_grey);

  const int sprite_width  = m_computer_grey->width();
  const int sprite_height = m_computer_grey->height();

  this->resize(2 * sprite_width,3 * sprite_height);
  this->mouseWentDown().connect(this, &ribi::con3::WtSelectPlayerWidget::OnClick);
  this->update();
}

ribi::con3::WtSelectPlayerWidget::~WtSelectPlayerWidget() noexcept
{
  delete m_computer_grey;
  for (auto& p: m_computers) delete p;
  for (auto& p: m_players) delete p;
  for (auto& p: m_players_grey) delete p;
}

void ribi::con3::WtSelectPlayerWidget::OnClick(const Wt::WMouseEvent& e)
{
  const int sprite_width  = m_computer_grey->width();
  const int sprite_height = m_computer_grey->height();

  const int mouse_x = e.widget().x;
  const int mouse_y = e.widget().y;
  const int index = mouse_y / sprite_height;
  const bool is_human = ( mouse_x / sprite_width == 0);
  m_is_player_human[index] = is_human;
  m_signal_on_clicked();
  this->update();
}

void ribi::con3::WtSelectPlayerWidget::paintEvent(Wt::WPaintDevice *paintDevice)
{
  Wt::WPainter painter(paintDevice);
  const int sprite_width  = m_computer_grey->width();
  const int sprite_height = m_computer_grey->height();

  painter.drawImage(0 * sprite_width,0 * sprite_height,m_is_player_human[0] ? *m_players[0]    : *m_players_grey[0]);
  painter.drawImage(0 * sprite_width,1 * sprite_height,m_is_player_human[1] ? *m_players[1]    : *m_players_grey[1]);
  painter.drawImage(0 * sprite_width,2 * sprite_height,m_is_player_human[2] ? *m_players[2]    : *m_players_grey[2]);
  painter.drawImage(1 * sprite_width,0 * sprite_height,m_is_player_human[0] ? *m_computer_grey : *m_computers[0]);
  painter.drawImage(1 * sprite_width,1 * sprite_height,m_is_player_human[1] ? *m_computer_grey : *m_computers[1]);
  painter.drawImage(1 * sprite_width,2 * sprite_height,m_is_player_human[2] ? *m_computer_grey : *m_computers[2]);
}


