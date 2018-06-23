#include "qtconnectthreegamedialog_test.h"
#include "qtconnectthreegamedialog.h"
#include <cassert>

#include "qtconnectthreegamedialog.h"
#include "connectthreeresources.h"

void ribi::con3::qtconnectthreegamedialog_test::construct()
{
  const Resources resources;
  const std::unique_ptr<const QtGameDialog> d {
    new QtGameDialog(resources,std::bitset<3>(false))
  };
  QVERIFY(d != nullptr);
}
