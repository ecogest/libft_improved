cmake_minimum_required (VERSION 3.0)

# Options
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project
project (ft)

# Sources
file (GLOB SRC
	libft_original/ft_*.c
	gnl/*.c
	)

# Create library
add_library (${PROJECT_NAME} STATIC ${SRC})

# Includes
target_include_directories (${PROJECT_NAME} PUBLIC ./includes)
