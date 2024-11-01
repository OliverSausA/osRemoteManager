#ifndef _APP_CONFIG_H
#define _APP_CONFIG_H

#include <string>

class AppConfig
{
public:
  AppConfig();

  std::string GetRepositoryPath();
};

#endif // _APP_CONFIG_H