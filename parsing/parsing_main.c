/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:11:55 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/12 12:01:17 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	leaks(void)
{
	system("leaks mini_shell");
}

int	main(int argc, char *argv[], char *envp[])
{
	argc++;
	argv++;
	envp++;
	
	char	*line;
	struct termios	term;
	t_cmd	*cmd;
	
	tcgetattr(0, &term);
	set_signal();
	while ((line = readline("minishell$ ")))
	{
		if ((line[0] != '\0') && (!iswhitespace(line))) // 빈문자열이 아니고 공백문자열이 아닐 때
		{
			cmd = make_cmd();
			init(cmd);
			add_history(line);
			tokenize_main(line, cmd);
			free_cmd(cmd);
		}
		free(line);
	}
	system("leaks  mini_shell");
	sig_term_handler(); // ctrl + D 핸들러
	tcsetattr(0, TCSANOW, &term);
}