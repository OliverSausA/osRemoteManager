#include "DeviceRepository.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <boost/json.hpp>
namespace json = boost::json;

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
  std::ofstream file(path);
  boost::json::value jv = boost::json::value_from(devices);
  PrettyPrint(file, jv);

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


void DeviceRepository::PrettyPrint( std::ostream& os, json::value const& jv, std::string* indent /*= nullptr*/ )
{
    std::string indent_;
    if(! indent)
        indent = &indent_;
    switch(jv.kind())
    {
    case json::kind::object:
    {
        os << "{\n";
        indent->append(4, ' ');
        auto const& obj = jv.get_object();
        if(! obj.empty())
        {
            auto it = obj.begin();
            for(;;)
            {
                os << *indent << json::serialize(it->key()) << " : ";
                PrettyPrint(os, it->value(), indent);
                if(++it == obj.end())
                    break;
                os << ",\n";
            }
        }
        os << "\n";
        indent->resize(indent->size() - 4);
        os << *indent << "}";
        break;
    }

    case json::kind::array:
    {
        os << "[\n";
        indent->append(4, ' ');
        auto const& arr = jv.get_array();
        if(! arr.empty())
        {
            auto it = arr.begin();
            for(;;)
            {
                os << *indent;
                PrettyPrint( os, *it, indent);
                if(++it == arr.end())
                    break;
                os << ",\n";
            }
        }
        os << "\n";
        indent->resize(indent->size() - 4);
        os << *indent << "]";
        break;
    }

    case json::kind::string:
    {
        os << json::serialize(jv.get_string());
        break;
    }

    case json::kind::uint64:
    case json::kind::int64:
    case json::kind::double_:
        os << jv;
        break;

    case json::kind::bool_:
        if(jv.get_bool())
            os << "true";
        else
            os << "false";
        break;

    case json::kind::null:
        os << "null";
        break;
    }

    if(indent->empty())
        os << "\n";
}
