#include "DeviceManager.h"
#include "DeviceRepository.h"
#include "../Models/AppConfig.h"

#include <iostream>

DeviceManager::DeviceManager(DeviceRepositoryPtr repository) : 
  deviceRepositoryPtr(repository),
  currentDeviceIdx(0)
{
}

void DeviceManager::Initialize()
{
  std::cout << "DeviceManager::Initialize" << std::endl;
  auto config = std::make_shared<AppConfig>();
  deviceRepositoryPtr->Load(config->GetRepositoryPath());
}

void DeviceManager::Cycle()
{
  std::cout << "DeviceManager::Cycle" << std::endl;
  std::shared_ptr<SDevice> device;
  if (currentDeviceIdx < deviceRepositoryPtr->GetCount())
    device = deviceRepositoryPtr->GetAt(currentDeviceIdx++);
  else
    currentDeviceIdx = 0;
  
  if (device)
    std::cout << "  device: " << device->Name << std::endl;
}

void DeviceManager::Terminate()
{
  std::cout << "DeviceManager::Terminate" << std::endl;
  auto config = std::make_shared<AppConfig>();
  deviceRepositoryPtr->Save(config->GetRepositoryPath());
}

bool DeviceManager::IsAlive()
{
  return true;
}
