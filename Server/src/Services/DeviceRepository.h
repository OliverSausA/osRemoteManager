#pragma once

#include "Models/Device.h"

class DeviceRepository
{
public:
  
  void Load();
  void Save();
  void Add( const SDevice& device );
  void Delete( const SDevice& device );

}