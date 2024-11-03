#include <boost/json.hpp>
#include "Device.h"

void tag_invoke( const boost::json::value_from_tag&, boost::json::value& jv, SDevice const& d )
{
  jv = {
    { "Name",  d.Name  },
    { "MAC",   d.MAC   },
    { "IP",    d.IP    },
    { "State", d.State }
  };
}

SDevice tag_invoke( const boost::json::value_to_tag<SDevice>, const boost::json::value& jv )
{
  SDevice device;
  auto const& obj = jv.as_object();
  device.Name = boost::json::value_to<std::string>(obj.at("Name"));
  device.MAC = boost::json::value_to<std::string>(obj.at("MAC"));
  device.IP = boost::json::value_to<std::string>(obj.at("IP"));
  device.State = (EDeviceState) boost::json::value_to<int>(obj.at("State"));
  return device;
}

void tag_invoke( const boost::json::value_from_tag&, boost::json::value& jv, std::vector<SDevice> const& v )
{
  boost::json::array json_array;
  for ( const auto& device : v )
    json_array.push_back(boost::json::value_from(device));
  jv = json_array;
}

std::vector<SDevice> tag_invoke( const boost::json::value_to_tag<std::vector<SDevice>>, const boost::json::value& jv)
{
  std::vector<SDevice> devices;
  for (const auto& device : jv.as_array())
    devices.push_back(boost::json::value_to<SDevice>(device));
  return devices; 
}