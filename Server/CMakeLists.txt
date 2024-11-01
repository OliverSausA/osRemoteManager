# osRemoteManager - Server

add_executable( osrmd
  src/main.cpp
  src/Models/AppConfig.cpp
  src/Models/Device.cpp
  src/Services/DeviceRepository.cpp
  src/Services/DeviceManager.cpp
  )

add_executable( osrmd_tests
  src/Models/Device.cpp
  tests/main_test.cpp
)

target_include_directories( 
  osrmd PUBLIC
  "${Boost_INCLUDE_DIRS}"
  )

target_link_libraries( osrmd
  ${Boost_LIBRARIES} 
  )

target_link_libraries( osrmd_tests
  ${Boost_LIBRARIES}
)
add_test(NAME osrmd_tests COMMAND osrmd_tests)
