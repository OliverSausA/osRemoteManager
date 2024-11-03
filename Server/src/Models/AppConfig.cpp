#include "AppConfig.h"
#include <filesystem>
#include <stdexcept>

AppConfig::AppConfig()
{
}

std::string AppConfig::GetRepositoryPath()
{
  auto homeDir = std::filesystem::path(getenv("HOME"));
  if (homeDir.empty())
    throw std::runtime_error("could not read home path");
  std::string s = homeDir;
  s.append("/.config/osRemoteManager/devices.json");
  return s;
}