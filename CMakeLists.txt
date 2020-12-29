cmake_minimum_required(VERSION 3.8)
project(polynomial-equations CXX)

option(POLYNOMIAL_EQUATIONS_ENABLE_TESTING "Build unit tests." ON)

if(POLYNOMIAL_EQUATIONS_ENABLE_TESTING)
  option(BUILD_GMOCK "Builds the googlemock subprojects" OFF)
  option(INSTALL_GTEST "Enables installation of googletest" OFF)
  add_subdirectory(third-party/googletest)

  add_subdirectory(test)
endif()