#include "connectthreemenudialog.h"

// Boost.Test does not play well with -Weffc++


#include <boost/test/unit_test.hpp>

using namespace ribi;
using namespace ribi::con3;

BOOST_AUTO_TEST_CASE(can_run)
{
  ribi::con3::MenuDialog d;
  d.Execute( { "connectthree" } );
}



