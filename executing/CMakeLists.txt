cmake_minimum_required(VERSION 3.10)
project(minishell C)

set(CMAKE_C_STANDARD 99)

# 설정된 라이브러리 경로
set(LIBFT_PATH "/Users/kyuminkim/Desktop/DEV/42_minishell/executing")

# 소스 파일 목록
set(SRCS
        builtin_func/cd.c
        builtin_func/echo.c
        builtin_func/env.c
        builtin_func/env_parsing_func.c
        builtin_func/exit.c
        builtin_func/export.c
        builtin_func/export_check_and_do.c
        builtin_func/export_check_validated.c
        builtin_func/export_do_export.c
        builtin_func/export_with_no_args.c
        utils/free_env.c
        utils/ft_strcmp.c
        main.c
        parse/check_operators.c
        parse/ckeck_quote.c
        parse/error_print.c
        parse/handler_env.c
        parse/handler_linked_list.c
        parse/init.c
        parse/make_nodes.c
        parse/parsing_utils.c
        parse/signal_hanlder.c
        parse/test.c
        parse/tokeniz.c
        utils/print_error.c
        builtin_func/pwd.c
        utils/size_func.c
        builtin_func/unset.c
        utils/value_utils.c
        builtin_execution.c
        execute_bin.c
        execute/executing.c
        execute/pipe_utils.c
        execute/free_executing_params.c
        execute/pipe_executing.c
        execute/normal_executing.c
        execute/executing_utils.c
        execute/executing_bin.c
        execute/redirect_executing.c
)

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

# 빌드에서 특정 파일을 제외하기 위한 설정
set_source_files_properties(
        ${CMAKE_BINARY_DIR}/CMakeFiles/3.27.8/CompilerIdC/CMakeCCompilerId.c.o
        ${CMAKE_BINARY_DIR}/CMakeFiles/3.28.1/CompilerIdC/CMakeCCompilerId.c.o
        PROPERTIES GENERATED TRUE EXCLUDE_FROM_ALL TRUE
)

# 중복 빌드를 방지하기 위한 설정
set_source_files_properties(
        ${CMAKE_BINARY_DIR}/CMakeFiles/3.27.8/CompilerIdC/CMakeCCompilerId.c
        ${CMAKE_BINARY_DIR}/CMakeFiles/3.28.1/CompilerIdC/CMakeCCompilerId.c
        PROPERTIES GENERATED TRUE EXCLUDE_FROM_ALL TRUE
)