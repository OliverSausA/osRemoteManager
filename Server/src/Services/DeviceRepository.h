#pragma once

#include <string>
#include <boost/json.hpp>
#include "DeviceRepositoryInterface.h"
#include "../Models/Device.h"

namespace json = boost::json;

class DeviceRepository : public IDeviceRepository
{
public:
  
  void Load(const std::string& path) override;
  void Save(const std::string& path) override;
  void Add( const SDevice& device ) override;
  void Delete( const SDevice& device ) override;

  std::shared_ptr<SDevice> GetAt(int i) override;
  int GetCount() override;

private:
  std::vector<SDevice> devices;

  void PrettyPrint( std::ostream& os, json::value const& jv, std::string* indent = nullptr );
};