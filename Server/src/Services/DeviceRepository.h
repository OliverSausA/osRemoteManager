#pragma once

#include <string_view>
#include "../Models/Device.h"

class DeviceRepository
{
public:
  
  void Load(std::string_view path);
  void Save();
  void Add( const SDevice& device );
  void Delete( const SDevice& device );

};