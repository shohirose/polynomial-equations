cmake_minimum_required(VERSION 3.8)
project(quadratic-equation CXX)

option(QUADRATIC_EQUATION_ENABLE_TESTING "Build unit tests." ON)

if(QUADRATIC_EQUATION_ENABLE_TESTING)
  enable_testing()
  find_package(GTest REQUIRED)
  add_executable(quadratic_equation_test
    test/quadratic_equation_test.cpp
  )
  target_include_directories(quadratic_equation_test
    PRIVATE
      ${PROJECT_SOURCE_DIR}/include
  )
  target_link_libraries(quadratic_equation_test
    PRIVATE
      GTest::GTest
      GTest::Main
  )
endif()