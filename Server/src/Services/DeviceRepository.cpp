#include "DeviceRepository.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <boost/json.hpp>


void DeviceRepository::Load(const std::string& path)
{
  devices.clear();

  std::ifstream file(path);
  if (!file) {
    throw std::runtime_error("could not read " + path);
  }
  std::ostringstream file_content;
  file_content << file.rdbuf();
  std::cout << "DeviceRepository::Load" << std::endl;
  std::cout << file_content.str() << std::endl;

  boost::json::value jv = boost::json::parse( file_content.str() );
  devices = boost::json::value_to<std::vector<SDevice>>(jv);
}
void DeviceRepository::Save(const std::string& path)
{

}
void DeviceRepository::Add( const SDevice& device )
{

}
void DeviceRepository::Delete( const SDevice& device )
{

}

std::shared_ptr<SDevice> DeviceRepository::GetAt(int i)
{
  if (i >= 0 && i < devices.capacity() )
    return std::make_shared<SDevice>(devices.at(i));
  return nullptr;
}

int DeviceRepository::GetCount()
{
  return devices.capacity();
}