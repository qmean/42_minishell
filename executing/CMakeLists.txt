cmake_minimum_required(VERSION 3.10)
project(minishell C)

set(CMAKE_C_STANDARD 99)

# 설정된 라이브러리 경로
set(LIBFT_PATH "./")

# 헤더를 추가하기 위해 설정 (현재 디렉토리 기준 하위 헤더 전부)
include_directories(.)

# 소스 파일 목록
file(GLOB SRCS
        "${PROJECT_SOURCE_DIR}/*.c"
        "${PROJECT_SOURCE_DIR}/builtin_func/*.c"
        "${PROJECT_SOURCE_DIR}/execute/*.c"
        "${PROJECT_SOURCE_DIR}/parse/*.c"
        "${PROJECT_SOURCE_DIR}/utils/*.c"
)

# 소스 파일 목록
set(SRCS ${SRCS}
        parse/check_redir_error.c)

# 인클루드 디렉토리 설정
include_directories(
        /opt/homebrew/opt/readline/include
        ${LIBFT_PATH}
)

# 라이브러리 디렉토리 설정
link_directories(
        /opt/homebrew/opt/readline/lib
        ${LIBFT_PATH}
)

# 실행 파일 생성
add_executable(minishell ${SRCS})

# 라이브러리 링크
target_link_libraries(minishell readline libft.a)
#
## 빌드에서 특정 파일을 제외하기 위한 설정
#set_source_files_properties(
#        ${CMAKE_BINARY_DIR}/CMakeFiles/3.27.8/CompilerIdC/CMakeCCompilerId.c.o
#        ${CMAKE_BINARY_DIR}/CMakeFiles/3.28.1/CompilerIdC/CMakeCCompilerId.c.o
#        PROPERTIES GENERATED TRUE EXCLUDE_FROM_ALL TRUE
#)
#
## 중복 빌드를 방지하기 위한 설정
#set_source_files_properties(
#        ${CMAKE_BINARY_DIR}/CMakeFiles/3.27.8/CompilerIdC/CMakeCCompilerId.c
#        ${CMAKE_BINARY_DIR}/CMakeFiles/3.28.1/CompilerIdC/CMakeCCompilerId.c
#        PROPERTIES GENERATED TRUE EXCLUDE_FROM_ALL TRUE
#)