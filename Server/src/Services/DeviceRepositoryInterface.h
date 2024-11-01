#pragma once
#include <string_view>
#include <memory>
#include "../Models/Device.h"

class IDeviceRepository;
typedef std::shared_ptr<IDeviceRepository> DeviceRepositoryPtr;

class IDeviceRepository
{
public:
  virtual void Load(std::string_view path) = 0;
  virtual void Save(std::string_view path) = 0;
  virtual void Add(const SDevice& device) = 0;
  virtual void Delete(const SDevice& device) = 0;
};