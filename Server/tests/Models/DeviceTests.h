#include <boost/test/included/unit_test.hpp>
#include <boost/json.hpp>
#include "../../src/Models/Device.h"

BOOST_AUTO_TEST_SUITE(DeviceTestSuite)

BOOST_AUTO_TEST_CASE( CreateDevice )
{
  SDevice* d = new SDevice();
  BOOST_TEST( d != nullptr );
}

BOOST_AUTO_TEST_CASE( CreateDeviceFromJSON )
{
  std::string json_test = "{\"Name\":\"DeviceName\",\"MAC\":\"AA:BB:CC:DD:EE:FF\",\"IP\":\"192.168.1.1\",\"State\":1}";
  boost::json::value jv = boost::json::parse( json_test );
  SDevice device = boost::json::value_to<SDevice>(jv);
  BOOST_TEST( device.Name  == "DeviceName" );
  BOOST_TEST( device.MAC   == "AA:BB:CC:DD:EE:FF" );
  BOOST_TEST( device.IP    == "192.168.1.1" );
  BOOST_TEST( device.State == EDeviceState::eRunning );
}

BOOST_AUTO_TEST_CASE( StreamDeviceToJSON )
{
  SDevice device = {
    "DeviceName", 
    "AA:BB:CC:DD:EE:FF", 
    "192.168.1.1", 
    EDeviceState::eRunning
  };

  boost::json::value jv = boost::json::value_from(device);
  std::string test = boost::json::serialize(jv);
  BOOST_TEST( test == "{\"Name\":\"DeviceName\",\"MAC\":\"AA:BB:CC:DD:EE:FF\",\"IP\":\"192.168.1.1\",\"State\":1}" );
}

BOOST_AUTO_TEST_CASE( CreateDeviceListFromJSON )
{
  std::string json_test = "[{\"Name\":\"DeviceName\",\"MAC\":\"AA:BB:CC:DD:EE:FF\",\"IP\":\"192.168.1.1\",\"State\":1},";
  json_test += "{\"Name\":\"DeviceName 2\",\"MAC\":\"AF:BE:CD:DC:EB:FA\",\"IP\":\"192.168.1.2\",\"State\":0}]";
  boost::json::value jv = boost::json::parse( json_test );
  std::vector<SDevice> devices = boost::json::value_to<std::vector<SDevice>>(jv);
  BOOST_TEST( devices[0].Name  == "DeviceName" );
  BOOST_TEST( devices[0].MAC   == "AA:BB:CC:DD:EE:FF" );
  BOOST_TEST( devices[0].IP    == "192.168.1.1" );
  BOOST_TEST( devices[0].State == EDeviceState::eRunning );
  BOOST_TEST( devices[1].Name  == "DeviceName 2" );
  BOOST_TEST( devices[1].MAC   == "AF:BE:CD:DC:EB:FA" );
  BOOST_TEST( devices[1].IP    == "192.168.1.2" );
  BOOST_TEST( devices[1].State == EDeviceState::eUnknown );
}

BOOST_AUTO_TEST_CASE( StreamDeviceListToJSON )
{
  std::vector<SDevice> devices = {
    {
      "DeviceName", 
      "AA:BB:CC:DD:EE:FF", 
      "192.168.1.1", 
      EDeviceState::eRunning
    },
    {
      "DeviceName 2", 
      "AF:BE:CD:DC:EB:FA", 
      "192.168.1.2", 
      EDeviceState::eUnknown
    }
  };
  boost::json::value jv = boost::json::value_from(devices);
  std::string test = boost::json::serialize(jv);

  std::string json_test = "[{\"Name\":\"DeviceName\",\"MAC\":\"AA:BB:CC:DD:EE:FF\",\"IP\":\"192.168.1.1\",\"State\":1},";
  json_test += "{\"Name\":\"DeviceName 2\",\"MAC\":\"AF:BE:CD:DC:EB:FA\",\"IP\":\"192.168.1.2\",\"State\":0}]";
  BOOST_TEST( test == json_test );
}

BOOST_AUTO_TEST_SUITE_END()
