#ifndef CONNECTTHREEMENUDIALOG_H
#define CONNECTTHREEMENUDIALOG_H

#include "menudialog.h"

namespace ribi {
namespace con3 {

struct MenuDialog final : public ::ribi::MenuDialog
{
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

} //~namespace con3
} //~namespace ribi

#endif // CONNECTTHREEMENUDIALOG_H
