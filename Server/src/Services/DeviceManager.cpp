#include "DeviceManager.h"
#include "DeviceRepository.h"
#include "../Models/AppConfig.h"

DeviceManager::DeviceManager(DeviceRepositoryPtr repository)
{
  deviceRepositoryPtr = repository;
}

void DeviceManager::Initialize()
{
  auto config = std::make_shared<AppConfig>();
  deviceRepositoryPtr->Load(config->GetRepositoryPath());
}

void DeviceManager::Cycle()
{

}

void DeviceManager::Terminate()
{
  auto config = std::make_shared<AppConfig>();
  deviceRepositoryPtr->Save(config->GetRepositoryPath());
}