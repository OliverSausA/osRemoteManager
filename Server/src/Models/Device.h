#ifndef _DEVICE_H
#define _DEVICE_H

#include <string>
#include <boost/json.hpp>
#include <boost/json/value_from.hpp>
#include <boost/json/value_to.hpp>

enum EDeviceState
{
  eUnknown = 0,
  eRunning
};

struct SDevice
{
  std::string Name;
  std::string MAC;
  std::string IP;
  EDeviceState State;
};

void tag_invoke( const boost::json::value_from_tag&, boost::json::value& jv, SDevice const& d );

SDevice tag_invoke( const boost::json::value_to_tag<SDevice>, const boost::json::value& jv );

void tag_invoke( const boost::json::value_from_tag&, boost::json::value& jv, std::vector<SDevice> const& v );

std::vector<SDevice> tag_invoke( const boost::json::value_to_tag<std::vector<SDevice>>, const boost::json::value& jv);
 
#endif //_DEVICE_H