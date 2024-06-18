/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:11:55 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/16 02:34:14 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	leaks(void)
{
	system("leaks mini_shell");
}

int	main(void)
{
	// argc++;
	// argv++;
	// envp++;
	
	char	*line;
	struct termios	term;
	t_line	cmds;
	
	tcgetattr(0, &term);
	set_signal();


	while ((line = readline("minishell$ ")))
	{
		if ((line[0] != '\0') && (!iswhitespace(line))) // 빈문자열이 아니고 공백문자열이 아닐 때
		{
			init(&cmds);
			cmds.cmds->env = malloc(sizeof(t_env));
			set_env(cmds.cmds->env);	
			add_history(line);
			tokenize_main(line, &cmds);
			free_cmd(&cmds);
		}
		free(line);
	}
	// system("leaks  mini_shell");
	sig_term_handler(); // ctrl + D 핸들러
	tcsetattr(0, TCSANOW, &term);
}