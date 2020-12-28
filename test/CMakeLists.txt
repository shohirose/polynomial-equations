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
      gtest_main
  )
  target_compile_options(${name}
    PRIVATE
      # Use static version of the run-time library to avoid linker errors
      $<$<CXX_COMPILER_ID:MSVC>:$<IF:$<CONFIG:Debug>,/MTd,/MT>>
  )
endfunction()

enable_testing()
add_unit_test(quadratic_equation_test)
add_unit_test(cubic_equation_test)