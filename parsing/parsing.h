/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:58:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/12 04:15:19 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libs/libft/libft.h"
// # include "../libs/get_next_line/get_next_line.h"

# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <termios.h>

typedef struct s_env
{
	char			*key;
	char			**value;
	struct s_env	*next;
}	t_env;

typedef struct	s_token
{
	int				redir; // 0: 아님 1: >, 2: <, 3: >>, 4: <<
	
	char			*redir_args[2]; // 리다이렉션 파일
	char			*data; // 명령어
	
	
	struct s_token	*next;
}				t_token;

typedef struct	s_cmd
{
	char			*buf; // 명령어를 저장할 버퍼
	int				pipe_flag; // 0 : NULL, 1 : pipe, 2: semicolon
	int				redirect; // 0: >, 1: <, 2: >>, 3: <<;
	char			quote; // 따옴표를 저장(' or "), 같은 따옴표가 나오면 다시 0으로 복귀

	t_token			*first_token; // 토큰의 첫번째 노드;
	struct s_cmd	*first_cmd; // 명령어 뭉치의 첫번째 노드
	
	t_token			*tokens; // 명령어를 저장할 연결리스트
	struct s_env	*env; // 환경 변수를 저장할 연결리스트
	struct s_cmd	*next; // 다음 명령어 뭉치
}				t_cmd;


int		iswhitespace(char *c);
void    set_signal(void);
void	signal_handler(int signo);
void    sigint_printc_off(void);
void    sigint_printc_on(void);
void    sig_term_handler(void);
t_cmd	*make_cmd(void);
t_token	*make_token(void);
void    init(t_cmd *cmd);
void    tokenize_main(char *line, t_cmd *cmd);
void    add_token(t_cmd *cmd);
int     check_pipe(char *line, t_cmd *cmd, int *i);
int     check_quote(char *line, t_cmd *cmd, int *i);
int     check_smallquote(char *line, t_cmd *cmd, int *i);
int     check_bigquote(char *line, t_cmd *cmd, int *i);
void    error_syntax(char *c);
void    error_invalid_quote(void);
int     check_escape(char *line, t_cmd *cmd, int *i);
int     check_semicolon(char *line, t_cmd *cmd, int *i);
void    add_cmd(t_cmd *cmd);
void    print_cmd(t_cmd *cmd);
void    print_token(t_token *token);
char	*ft_strjoin_free(char *s1, char s2);

#endif