# osRemoteManager - Server

add_executable( osrmd
  src/main.cpp
  )

add_executable( osrmd_tests
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
