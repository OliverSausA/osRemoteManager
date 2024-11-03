#pragma once
#include <string>
#include <memory>
#include "../Models/Device.h"

class IDeviceRepository;
typedef std::shared_ptr<IDeviceRepository> DeviceRepositoryPtr;

class IDeviceRepository
{
public:
  virtual void Load(const std::string& path) = 0;
  virtual void Save(const std::string& path) = 0;
  virtual void Add(const SDevice& device) = 0;
  virtual void Delete(const SDevice& device) = 0;

  virtual std::shared_ptr<SDevice> GetAt(int i) = 0;
  virtual int GetCount() = 0;
};