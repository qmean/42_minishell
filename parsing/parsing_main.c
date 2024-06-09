/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:11:55 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/10 00:26:10 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_cmd	cmd;

	argc++;
	argv++;
	envp++;
	set_signal();
	init(&cmd);
	while ((line = readline("minishell$ ")))
	{
		if ((line[0] != '\0') && (iswhitespace(line))) // NULL이거나 공백일 경우
		{
			add_history(line);
		}
	}
	sig_term_handler(); // ctrl + D 핸들러
}