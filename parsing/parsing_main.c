/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:11:55 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/08 03:28:14 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	argc++;
	argv++;
	envp++;
		set_signal();
		while ((line = readline("minishell$ ")))
		if ((line[0] != '\0')&& (!iswhitespace(line)))
		{
			add_history(line);
		}
}