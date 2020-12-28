cmake_minimum_required(VERSION 3.8)
project(quadratic-equation CXX)

option(QUADRATIC_EQUATION_ENABLE_TESTING "Build unit tests." ON)

if(QUADRATIC_EQUATION_ENABLE_TESTING)
  option(BUILD_GMOCK "Builds the googlemock subprojects" OFF)
  option(INSTALL_GTEST "Enables installation of googletest" OFF)
  add_subdirectory(third-party/googletest)

  add_subdirectory(test)
endif()