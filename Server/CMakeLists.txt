# osRemoteManager - Server

add_executable( osrmd
  src/main.cpp
  )

target_include_directories( 
  osrmd PUBLIC
  "${Boost_INCLUDE_DIRS}"
  )

target_link_libraries( osrmd
  ${Boost_LIBRARIES} 
  )
