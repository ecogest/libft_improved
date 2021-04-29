cmake_minimum_required (VERSION 3.14)

# Options
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_C_COMPILER clang)

# Project
project (ft)

# Sources
file (GLOB SRC
	ft_*/*.c
	gnl/*.c
	)

# Create library
add_library (${PROJECT_NAME} STATIC ${SRC})

# Includes
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra)
target_include_directories (${PROJECT_NAME} PUBLIC ./includes)

enable_testing ()
add_subdirectory (tests)
