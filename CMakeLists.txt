cmake_minimum_required(VERSION 3.8)
project(quadratic-equation CXX)

option(QUADRATIC_EQUATION_ENABLE_TESTING "Build unit tests." ON)

if(QUADRATIC_EQUATION_ENABLE_TESTING)
  add_subdirectory(test)
endif()