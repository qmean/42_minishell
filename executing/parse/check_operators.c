/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:11:44 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/06 17:46:25 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_pipe(char *line, t_line *lines, int *i)
{
	if (line[*i] == '|')
	{
		if (lines->cmds->quote == 0)
		{
			line[*i] = '\0';
			if (lines->cmds->buf != NULL)
				add_token(lines->cmds);
			lines->pipe_flag = 1;
			add_cmd(lines);
			*i += 1;
			if (line[*i] == '|')
			{
				if ((line[*i + 2] == '|') && (line[*i + 1] == '|'))
					return (error_syntax("||"));
				if (line[*i + 1] == '|')
					return (error_syntax("|"));
				*i += 1;
			}
			return (1);
		}
	}
	return (0);
}

int	check_space(char *line, t_cmd *cmd, int *i)
{
	if (line[*i] == ' ')
	{
		if (cmd->quote == 0)
		{
			if (cmd->buf != NULL)
			{
				cmd->tokens->isspace = 1;
				add_token(cmd);
			}
			*i += 1;
			return (1);
		}
	}
	return (0);
}

int	check_redir(char *line, t_line *lines, int *i)
{
	int	ret;

	ret = check_redir_right(line, lines, i);
	if (ret != 0)
		return (ret);
	ret = check_redir_left(line, lines, i);
	return (ret);
}

int	check_redir_right(char *line, t_line *lines, int *i)
{
	int	ret;

	if ((lines->cmds->quote == 0) && (line[*i] == '>'))
	{
		*i += 1;
		if (lines->cmds->buf != NULL)
			add_token(lines->cmds);
		lines->cmds->tokens->redir = 3;
		if (line[*i] == '>')
		{
			*i += 1;
			lines->cmds->tokens->redir = 4;
			ret = check_redir_syntax1(line, *i);
			if (ret)
				return (ret);
		}
		ret = check_redir_syntax3(line, i);
		if (ret)
			return (ret);
		return (1);
	}
	return (0);
}

int	check_redir_left(char *line, t_line *lines, int *i)
{
	if ((lines->cmds->quote == 0) && (line[*i] == '<'))
	{
		*i += 1;
		if (lines->cmds->buf != NULL)
			add_token(lines->cmds);
		lines->cmds->tokens->redir = 1;
		if (line[*i] == '<')
		{
			*i += 1;
			lines->cmds->tokens->redir = 2;
			if (line[*i] == '<')
				return (check_redir_syntax4(line, i));
			if (line[*i] == '>')
				return (error_syntax(">"));
		}
		if (line[*i] == '|')
			return (error_syntax("|"));
		return (1);
	}
	return (0);
}
