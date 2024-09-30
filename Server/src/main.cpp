/*=================================================================================================
 * osRemoteManager - Server
 *===============================================================================================*/
#include <iostream>
#include <boost/program_options.hpp>

using namespace boost::program_options;

//-------------------------------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  std::cout << "Das muss erst noch ein Server werden!\n";

  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen");
    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  

  return 0;
}
