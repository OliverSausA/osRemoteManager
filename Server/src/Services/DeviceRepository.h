#pragma once

#include <string_view>
#include "DeviceRepositoryInterface.h"
#include "../Models/Device.h"

class DeviceRepository : public IDeviceRepository
{
public:
  
  void Load(std::string_view path) override;
  void Save(std::string_view path) override;
  void Add( const SDevice& device ) override;
  void Delete( const SDevice& device ) override;
};