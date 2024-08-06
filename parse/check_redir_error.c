/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:46:42 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 01:13:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_redir_syntax1(char *line, int i)
{
	if (line[i] == '>')
	{
		if (line[i + 1] == '>')
			return (error_syntax(">>"));
		if (line[i + 1] == '|')
			return (error_syntax(">|"));
		return (error_syntax(">"));
	}
	if (line[i] == '|')
		return (error_syntax("|"));
	return (0);
}

int	check_redir_syntax2(char *line, int *i)
{
	if (line[*i] == '<')
	{
		while (line[*i] == ' ')
			*i += 1;
		if (line[*i + 1] == '<')
			return (error_syntax("<<<"));
		return (error_syntax("<<"));
	}
	if (line[*i] == '>')
		return (error_syntax("<>"));
	return (error_syntax("<"));
}

int	check_redir_syntax3(char *line, int *i)
{
	if (line[*i] == '<')
	{
		*i += 1;
		return (check_redir_syntax2(line, i));
	}
	if (line[*i] == '|')
		return (error_syntax(""));
	return (0);
}

int	check_redir_syntax4(char *line, int *i)
{
	if (line[*i + 1] == '<')
	{
		if (line[*i + 2] == '<')
		{
			if (line[*i + 3] == '<')
				return (error_syntax("<<<"));
			return (error_syntax("<<"));
		}
		if (line[*i + 2] == '>')
			return (error_syntax("<>"));
		return (error_syntax("<"));
	}
	if (line[*i + 1] == '>')
		return (error_syntax(">"));
	if (line[*i + 1] == '|')
		return (error_syntax("|"));
	return (0);
}
