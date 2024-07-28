/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:58:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/07/29 03:57:28 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <stdio.h>

#include "../libft.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <termios.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct	s_token
{
	int				isspace; // 마지막에 space로 토큰을 나누었는지 아닌지 -> 0: 아님 1: 공백
	char			*data; // 명령어
	int				redir; // 리다이렉션 플래그 0: 없음 1: < 2: << 3: > 4: >>

	struct s_token	*next;
}				t_token;

typedef struct	s_cmd
{
	char			*buf; // 명령어를 저장할 버퍼
	char			quote; // 따옴표를 저장(' or "), 같은 따옴표가 나오면 다시 0으로 복귀
	int				input_file; // 입력 리다이렉션 파일fd -2로 초기화 0이면 <<
	int				output_file; // 출력 리다이렉션 파일fd -2로 초기화
	char			*heredoc_str;

	int				pipe[2];
	t_token			*first_token; // 토큰의 첫번째 노드;
	t_token			*tokens; // 명령어를 저장할 연결리스트
	t_env			*env; // 환경 변수를 저장할 연결리스트
	struct s_cmd	*next; // 다음 명령어 뭉치
}				t_cmd;

typedef struct s_line
{
	t_cmd	*first_cmd; // 명령어 뭉치의 첫번째 노드
	t_cmd	*cmds; // 명령어 뭉치를 저장할 연결리스트
	t_env	*env; // 환경 변수를 저장할 연결리스트
	int		pipe_flag; // 0 : NULL, 1 : pipe
	int		exit_flag; // exit 상태 저장
} t_line;

int		iswhitespace(char *c);
void    set_signal(void);
void	signal_handler(int signo);
void    sigint_printc_off(void);
void    sigint_printc_on(void);
void    sig_term_handler(void);
t_cmd	*make_cmd(void);
t_token	*make_token(void);
void    init(t_line *lines);
void	tokenize_main(char *line, t_line *lines);
void    add_token(t_cmd *cmd);
int 	check_pipe(char *line, t_line *lines, int *i);
int     check_quote(char *line, t_cmd *cmd, int *i);
int     check_smallquote(char *line, t_cmd *cmd, int *i);
int     check_bigquote(char *line, t_cmd *cmd, int *i);
int		error_syntax(char *c);
int		error_invalid_quote(void);
int     check_escape(char *line, t_line *lines, int *i);
int     check_semicolon(char *line, t_line *lines, int *i);
void	add_cmd(t_line *lines);
char	*ft_strjoin_free(char *s1, char s2);
void	free_cmd(t_line *lines);
void    free_token(t_token *token);
int		check_space(char *line, t_cmd *cmd, int *i);
int		check_env(char *line, t_line *lines, int *i);
void    get_env_value(char *key, t_line *line);
int		ft_strcmp_par(const char *s1, const char *s2);
int		check_issue(char *line, t_line *lines, int *i);
int		check_redir(char *line, t_line *lines, int *i);
int		check_redir_right(char *line, t_line *lines, int *i);
int		check_redir_left(char *line, t_line *lines, int *i);
int		check_syntax(t_line *lines);
void    print_cmd(t_line *lines);
int		error_nofile(char *c);
int     input_redirection(t_cmd *cmds);
void	make_redir_token(t_token *token, t_token *next);
void	free_last_token(t_line *lines);
int     output_redirection(t_cmd *cmds);
int     output_append_redirection(t_cmd *cmds);
int		input_heredoc_redirection(t_cmd *cmds);

#endif