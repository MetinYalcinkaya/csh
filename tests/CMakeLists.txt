include(FetchContent)
FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG v2.6.1
)
FetchContent_MakeAvailable(unity)

# test files
set(TEST_FILES
  test_shell.c
  test_builtins.c
)

foreach(test_file ${TEST_FILES})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_executable(${test_name} ${test_file})
  target_link_libraries(${test_name} PRIVATE shell_lib unity)
  add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
