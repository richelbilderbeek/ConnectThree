

#include "connectthreeresources.h"

#include <cassert>
#include <cstdio>
#include <stdexcept>

#include "fileio.h"


#include <QFile>



ribi::con3::Resources::Resources()
  : Resources(
    {
      "ConnectThreeComputer1.png",
      "ConnectThreeComputer2.png",
      "ConnectThreeComputer3.png"
    },
    "ConnectThreeComputerGrey.png",
    "ConnectThree.css",
    "ConnectThreeEmpty.png",
    "ConnectThreeIcon.png",
    {
      "ConnectThreeGood1.png",
      "ConnectThreeGood2.png"
    },
    "ConnectThreeWrong.png",
    {
      "ConnectThreePlayer1.png",
      "ConnectThreePlayer2.png",
      "ConnectThreePlayer3.png"
    },
    {
      "ConnectThreePlayer1Grey.png",
      "ConnectThreePlayer2Grey.png",
      "ConnectThreePlayer3Grey.png"
    },
    "Quit",
    "Winner"
  )
{
  Create();
}

ribi::con3::Resources::Resources(
  const std::vector<std::string>& computers_filenames,
  const std::string& computer_grey_filename,
  const std::string& css,
  const std::string& empty_filename,
  const std::string& icon_filename,
  const std::vector<std::string>& instructions_good_filenames,
  const std::string& instructions_wrong_filename,
  const std::vector<std::string>& players_filenames,
  const std::vector<std::string>& players_grey_filenames,
  const std::string& quit_text,
  const std::string& winner_text
  )
  : m_computers_filenames(computers_filenames),
    m_computer_grey_filename(computer_grey_filename),
    m_css(css),
    m_empty_filename(empty_filename),
    m_icon_filename(icon_filename),
    m_instructions_good_filenames(instructions_good_filenames),
    m_instructions_wrong_filename(instructions_wrong_filename),
    m_players_filenames(players_filenames),
    m_players_grey_filenames(players_grey_filenames),
    m_quit_text(quit_text),
    m_winner_text(winner_text)
{
  Create();
}

void ribi::con3::Resources::Create() const
{
  //CheckFile(m_background_filename);
  for (const std::string& filename: m_computers_filenames) { CreateFile(filename); }
  for (const std::string& filename: m_players_filenames) { CreateFile(filename); }
  for (const std::string& filename: m_players_grey_filenames) { CreateFile(filename); }
  CreateFile(m_computer_grey_filename);
  CreateFile(m_css);
  CreateFile(m_empty_filename);
  CreateFile(m_icon_filename);
  CreateFile(m_instructions_good_filenames[0]);
  CreateFile(m_instructions_good_filenames[1]);
  CreateFile(m_instructions_wrong_filename);
}

void ribi::con3::Resources::CreateFile(const std::string& s)
{
  if (!fileio::FileIo().IsRegularFile(s))
  {
    const std::string filename = ":/images/" + s;
    QFile f(filename.c_str());
    f.copy(s.c_str());
    if (!fileio::FileIo().IsRegularFile(s))
    {
      const std::string error = "Resources::CreateFile: file not found: '" + s
        + "\', please add the file to a resource file, or correct the filename";
      throw std::runtime_error(error);
    }
  }
  assert(fileio::FileIo().IsRegularFile(s));
}

///Removes all files
void ribi::con3::Resources::RemoveFiles() const noexcept
{
  for (const std::string& filename: m_computers_filenames) { std::remove(filename.c_str()); }
  for (const std::string& filename: m_players_filenames) { std::remove(filename.c_str()); }
  for (const std::string& filename: m_players_grey_filenames) { std::remove(filename.c_str()); }
  for (const std::string& filename: m_instructions_good_filenames) { std::remove(filename.c_str()); }
  std::remove(m_computer_grey_filename.c_str());
  std::remove(m_css.c_str());
  std::remove(m_empty_filename.c_str());
  std::remove(m_icon_filename.c_str());
  std::remove(m_instructions_wrong_filename.c_str());
}
