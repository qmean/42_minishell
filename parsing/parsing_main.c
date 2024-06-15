/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:11:55 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/10 03:00:37 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	struct termios	term;
	t_cmd	cmd;

	argc++;
	argv++;
	envp++;
	tcgetattr(0, &term);
	set_signal();
	while ((line = readline("minishell$ ")))
	{
		if ((line[0] != '\0') && (iswhitespace(line))) // 빈문자열이 아니고 공백문자열이 아닐 때
		{
			add_history(line);
			tokenize_main(line, &cmd);
		}
		free(line);
	}
	sig_term_handler(); // ctrl + D 핸들러
	tcsetattr(0, TCSANOW, &term);
}