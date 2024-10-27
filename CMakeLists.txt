# osRemoteManager
#
# usage of cmake:
# 1. configure
#    $ mkdir build
#    $ cd build
#    build$ cmake ..
# 2. compile
#    build$ cmake --build .
# 3. install
#    build$ cmake --install . --prefix /opt
#
# Oliver Seidel, 26.9.2024

# cmake requirements
cmake_minimum_required( VERSION 3.20 )
include(${CMAKE_CURRENT_SOURCE_DIR}/utility.cmake)

# set the project name and Version
project( osRemoteManager VERSION 0.1 )

# specify c++ standard
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

# boost library
# https://stackoverflow.com/questions/54581717/adding-boost-to-cmake-project
set( BOOST_ROOT ${CMAKE_SOURCE_DIR}/../3rdParty/boost )
set( BOOST_USE_STATIC_LIBS OFF )
set( BOOST_USE_MULTITHREADED ON )
set( BOOST_USE_STATIC_RUNTIME OFF )
find_package( Boost 1.86 REQUIRED COMPONENTS 
    system 
    program_options  
    unit_test_framework
)
include_directories( ${Boost_INCLUDE_DIR} )
#dump_cmake_variables( "boost" )

enable_testing()

add_subdirectory( Server )
