cmake_minimum_required(VERSION 3.10)
project(mini_shell VERSION 1.0)

# Compiler flags
set(CMAKE_C_COMPILER "cc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/parsing)
include_directories(${PROJECT_SOURCE_DIR}/libs/libft)
include_directories(/opt/homebrew/opt/readline/include)

# Source files
# Source files
file(GLOB PARSING_SRCS "${PROJECT_SOURCE_DIR}/parsing/*.c")
file(GLOB LIBFT_SRCS "${PROJECT_SOURCE_DIR}/libs/libft/*.c")

set(LIBFT_SRCS
        libs/libft/ft_putstr_fd.c
        libs/libft/ft_strlen.c
        libs/libft/ft_putchar_fd.c
        libs/libft/ft_strlcpy.c
)

# Executable
add_executable(${PROJECT_NAME}
        ${PARSING_SRCS}
        ${LIBFT_SRCS}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} readline)
target_link_directories(${PROJECT_NAME} PRIVATE /opt/homebrew/opt/readline/lib)