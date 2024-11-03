#ifndef _DEVICE_MANAGER_H
#define _DEVICE_MANAGER_H

#include "DeviceRepositoryInterface.h"

class DeviceManager
{
public:
  DeviceManager(DeviceRepositoryPtr repository);

  void Initialize();
  void Cycle();
  void Terminate();
  bool IsAlive();

private:
  DeviceRepositoryPtr deviceRepositoryPtr;
  int currentDeviceIdx;
};

#endif // _DEVICE_MANAGER_H