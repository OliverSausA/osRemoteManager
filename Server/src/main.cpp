/*=================================================================================================
 * osRemoteManager - Server
 *===============================================================================================*/
#include <iostream>
#include <chrono>
#include <csignal>
#include <unistd.h>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/program_options.hpp>

#include "Services/DeviceManager.h"
#include "Services/DeviceRepository.h"

using namespace boost::program_options;

bool RUNNING = true;
long cycle = 0;

//-------------------------------------------------------------------------------------------------
void signalHandler(int signum)
{
  if (signum == SIGINT )
    RUNNING = false;
  else
    exit(signum);
}

//-------------------------------------------------------------------------------------------------
void main_cycle(const boost::system::error_code& /*e*/,
                boost::asio::steady_timer* timer,
                DeviceManager* manager,
                int intervall) 
{
  std::cout << "main_cycle " << ++cycle << std::endl;
  if (!RUNNING) return;

  manager->Cycle();

  timer->expires_after(std::chrono::milliseconds(intervall));
  timer->async_wait(boost::bind(main_cycle, boost::placeholders::_1, timer, manager, intervall));
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

    std::cout << "Initialize" << std::endl;

    DeviceRepositoryPtr deviceRepository = std::make_shared<DeviceRepository>();
    DeviceManager deviceManager(deviceRepository);
    deviceManager.Initialize();

    boost::asio::io_context io;
    int intervall = 1000;
    boost::asio::steady_timer timer(io, std::chrono::milliseconds(intervall));
    timer.async_wait(boost::bind(main_cycle, boost::placeholders::_1, &timer, &deviceManager, intervall));
    io.run();

    std::cout << "Terminate" << std::endl;
    deviceManager.Terminate();
  }

  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
