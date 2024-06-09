/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:58:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/09 22:46:39 by jaemikim         ###   ########.fr       */
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

typedef struct	s_line
{
	char			*cmd;
	char			redir_flag;
}				t_line;

typedef struct s_env
{
	char			*key;
	char			**value;
	struct s_env	*next;
}	t_env;

typedef struct	s_token
{
	int				isredir; // 0: 아님 1: 리다이렉션
	char			*data; // 명령어
	
	struct s_token	*next;
}				t_token;

typedef struct	s_cmd
{
	t_line			*next_token;
	
	int				pipe_flag; // 0 : 세미 콜론 or NULL, 1 : pipe
	int				redirect; // 0: >, 1: <, 2: >>, 3: <<;
	int				exit_flag;
	char			quote; // 따옴표를 저장(' or "), 같은 따옴표가 나오면 다시 0으로 복귀
	t_token			*tokens; // 명령어를 저장할 연결리스트
	

	struct s_env	*env;
	struct s_cmd			*next;
}				t_cmd;


int		iswhitespace(char *c);
void    set_signal(void);
void	signal_handler(int signo);
void    sigint_printc_off(void);
void    sigint_printc_on(void);
void    sig_term_handler(void);

#endif