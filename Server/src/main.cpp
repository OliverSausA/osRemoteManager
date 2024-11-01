/*=================================================================================================
 * osRemoteManager - Server
 *===============================================================================================*/
#include <iostream>
#include <csignal>
#include <unistd.h>
#include <boost/program_options.hpp>

#include "Services/DeviceManager.h"
#include "Services/DeviceRepository.h"

using namespace boost::program_options;

bool RUNNING = true;

void signalHandler(int signum)
{
  if (signum == SIGINT )
    RUNNING = false;
  else
    exit(signum);
}

//-------------------------------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  std::signal(SIGINT,  signalHandler);
  std::signal(SIGTERM, signalHandler);

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
    {
      std::cout << desc << '\n';
      return 0;
    }

    DeviceRepositoryPtr deviceRepository = std::make_shared<DeviceRepository>();
    auto deviceManager = std::make_shared<DeviceManager>(deviceRepository);
    deviceManager->Initialize();

    while (RUNNING)
    {
      deviceManager->Cycle();
      sleep(10);
    }
    deviceManager->Terminate();
  }

  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
