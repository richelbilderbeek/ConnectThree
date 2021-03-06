#ifndef CONNECTTHREERESOURCES_H
#define CONNECTTHREERESOURCES_H

#include <string>
#include <vector>

namespace ribi {
namespace con3 {

///Resources contains all resources' filenames
///and checks that these are present
struct Resources
{
  Resources();

  ///Creates all resources
  ///Throws std::runtime_error if one of these cannot be created from resources
  Resources(
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
    );

  ///Creates a file
  ///Throws std::runtime_error if it cannot be created from resources
  static void CreateFile(const std::string& s);

  //const std::string& GetBackgroundFilename() const { return m_background_filename; }
  const std::string& GetCss() const noexcept { return m_css; }
  const std::vector<std::string>& GetComputersFilenames() const noexcept { return  m_computers_filenames; }
  const std::string& GetComputerGreyFilename() const noexcept { return m_computer_grey_filename; }
  const std::string& GetEmptyFilename() const noexcept { return m_empty_filename; }
  const std::string& GetIconFilename() const noexcept { return m_icon_filename; }
  const std::vector<std::string>& GetInstructionsGoodFilenames() const noexcept { return  m_instructions_good_filenames; }
  const std::string& GetInstructionsWrongFilename() const noexcept { return m_instructions_wrong_filename; }
  const std::vector<std::string>& GetPlayersFilenames() const noexcept { return  m_players_filenames; }
  const std::vector<std::string>& GetPlayersGreyFilenames() const noexcept { return  m_players_grey_filenames; }

  ///The text displayed at the Quit button
  const std::string& GetQuitText() const noexcept { return m_quit_text; }

  ///The text display at the Winner dialog
  const std::string& GetWinnerText() const noexcept { return m_winner_text; }

  ///Removes all files
  void RemoveFiles() const noexcept;

  private:
  const std::vector<std::string> m_computers_filenames;
  const std::string m_computer_grey_filename;
  const std::string m_css;
  const std::string m_empty_filename;
  const std::string m_icon_filename;
  const std::vector<std::string> m_instructions_good_filenames;
  const std::string m_instructions_wrong_filename;
  const std::vector<std::string> m_players_filenames;
  const std::vector<std::string> m_players_grey_filenames;
  const std::string m_quit_text;
  const std::string m_winner_text;
  private:

  ///Creates all files
  ///Throws std::runtime_error if one of these cannot be created from resources
  void Create() const;
};

} //~namespace con3
} //~namespace ribi

#endif // CONNECTTHREERESOURCES_H
