#include <cassert>
#include <iostream>

#include "qtconnectthreegamedialog_test.h"

#include <QtTest/QtTest>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  int error = 0;
  { ribi::con3::qtconnectthreegamedialog_test t; error |= QTest::qExec(&t, argc, argv); }
  if (error == 0) { std::cout << "Pass\n"; }
  if (error != 0) { std::cout << "Fail\n"; }
  return error;
}
