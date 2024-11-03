#pragma once

#include <string>
#include "DeviceRepositoryInterface.h"
#include "../Models/Device.h"

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
};