#pragma once

#include <string>

enum EDeviceState
{
  eUnknown = 0,
  eRunning
};

struct SDevice
{
  std::string Name;
  std::string MAC;
  std::string IP;
  EDeviceState State;
};
