#include <iostream>

#include "connectthreemenudialog.h"

int main(int argc, char * argv[])
{
  const std::vector<std::string> args { ribi::MenuDialog::ConvertArguments(argc,argv) };
  return ribi::con3::MenuDialog().Execute(args);
}
