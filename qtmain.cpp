#pragma GCC diagnostic push



#include <QApplication>

#include <cassert>
#include "fileio.h"
#include "qtconnectthreemenudialog.h"
#include "trace.h"

#include <QFile>
#include <QIcon>
#pragma GCC diagnostic pop

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  START_TRACE();
  ribi::con3::Resources resources;

  ribi::con3::QtMenuDialog w(resources);
  {
    const std::string icon_filename = resources.GetIconFilename();
    assert(ribi::fileio::FileIo().IsRegularFile(icon_filename.c_str()));
    w.setWindowIcon(QIcon(QPixmap(icon_filename.c_str())));
  }
  w.show();
  return a.exec();
}
