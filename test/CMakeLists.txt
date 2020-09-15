enable_testing()
find_package(GTest REQUIRED)

function(add_unit_test name)
  add_executable(${name}
    ${PROJECT_SOURCE_DIR}/test/${name}.cpp
  )
  target_include_directories(${name}
    PRIVATE
      ${PROJECT_SOURCE_DIR}/include
  )
  target_link_libraries(${name}
    PRIVATE
      GTest::GTest
      GTest::Main
  )
endfunction()

add_unit_test(quadratic_equation_test)
add_unit_test(cubic_equation_test)