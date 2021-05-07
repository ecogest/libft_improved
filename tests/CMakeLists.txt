set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_COMPILER clang++)
find_package(GTest CONFIG REQUIRED)

set (TESTER_NAME UnitTests)

set (TEST_SRCS
# ========================== ADD TEST SOURCES BELOW ========================== #
  ft_is/test_ft_isprint.cc
  ft_is/test_ft_isdigit.cc
  ft_is/test_ft_isascii.cc
  ft_is/test_ft_isalpha.cc
  ft_is/test_ft_isalnum.cc
  test_ft_strcmp.cc
  )

add_executable (${TESTER_NAME} ${TEST_SRCS})
target_link_libraries (${TESTER_NAME}
                       ft
                       GTest::gtest
                       GTest::gtest_main
                       )

# # Run all tests with ctest:
#
# add_test (
#   NAME MyTest
#   COMMAND ${TESTER_NAME}
#   )

# Better option call add_test for each test with embeded cmake google test module:
include (GoogleTest)
gtest_discover_tests (${TESTER_NAME})
