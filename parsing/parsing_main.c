/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:11:55 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/14 03:52:40 by jammin           ###   ########.fr       */
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