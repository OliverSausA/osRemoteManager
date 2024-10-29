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

BOOST_AUTO_TEST_SUITE_END()
