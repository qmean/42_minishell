cmake_minimum_required(VERSION 3.10)
project(minishell C)

set(CMAKE_C_STANDARD 99)

# Collect all C source files in the current directory
file(GLOB SOURCES "*.c")

# Specify the .a library file in the source directory
set(LIBRARIES "${CMAKE_SOURCE_DIR}/libft.a;${CMAKE_SOURCE_DIR}/get_next_line.a")

# Add the executable
add_executable(minishell ${SOURCES}
        env_parsing_func.c
        executing.c
        cmd_func.c)

# Link the library
target_link_libraries(minishell ${LIBRARIES})
target_link_libraries(minishell readline)