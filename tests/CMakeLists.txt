set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_COMPILER clang++)
find_package(GTest CONFIG REQUIRED)

set (TESTER_NAME UnitTests)

set (TEST_SRCS
# ========================== ADD TEST SOURCES BELOW ========================== #
  ft_str/ft_strnjoin_test.cc
  ft_str/ft_strappend_test.cc
  ft_str/ft_strjoin_test.cc
  ft_mem/ft_calloc_test.cc
  ft_str/ft_strnew_test.cc
  ft_str/ft_strlen_test.cc
  ft_str/ft_strdup_test.cc
  ft_mem/ft_memdel_test.cc
  ft_str/ft_strdel_test.cc
  ft_str/ft_strlcat_test.cc
  ft_str/ft_strncat_test.cc
  ft_str/ft_strlcpy_test.cc
  ft_str/ft_strncpy_test.cc
  ft_str/ft_strcat_test.cc
  ft_str/ft_strcpy_test.cc
  ft_str/ft_strncmp_test.cc
  ft_str/ft_strcmp_test.cc
  ft_str/ft_strchr_test.cc
  ft_str/ft_strstr_test.cc
  ft_str/ft_strtrim_test.cc
  ft_str/ft_substr_test.cc
  ft_str/ft_split_test.cc
  gnl/get_next_line_test.cc
  ft_to/ft_wctomb_test.cc
  ft_to/ft_toupper_test.cc
  ft_to/ft_tolower_test.cc
  ft_to/ft_itoa_base_test.cc
  ft_to/ft_itoa_test.cc
  ft_to/ft_atoi_test.cc
  ft_is/ft_isprint_test.cc
  ft_is/ft_isdigit_test.cc
  ft_is/ft_isascii_test.cc
  ft_is/ft_isalpha_test.cc
  ft_is/ft_isalnum_test.cc
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
