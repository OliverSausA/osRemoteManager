#include "AppConfig.h"

AppConfig::AppConfig()
{
}

std::string AppConfig::GetRepositoryPath()
{
  return "~/.config/osRemoteManager/devices.json";
}