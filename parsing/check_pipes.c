/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:11:44 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/12 04:15:45 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_pipe(char *line, t_cmd *cmd, int *i)
{
    if (line[*i] == '|')
    {
        if (cmd->quote == 0)
        {
            cmd->pipe_flag = 1;
            line[*i] = '\0';
            add_token(cmd);
            add_cmd(cmd);
            return (1);
        }
    }
    return (0);
}

int check_escape(char *line, t_cmd *cmd, int *i)
{
    if (line[*i] == '\\')
    {
        if (cmd->quote == 0)
        {
            *i += 1;
            if (line[*i] == '\0')
                error_syntax("'\0'");
        }
        else if (cmd->quote == '\"')
        {
            *i += 1;
            if (line[*i] == '\0')
                error_invalid_quote();
            else if (line[*i] == '\"')
            {
                cmd->buf = ft_strjoin_free(cmd->buf, '\"');
                *i += 1;
            }
            else if (line[*i] == '\\')
            {
                cmd->buf = ft_strjoin_free(cmd->buf, '\\');
                *i += 1;
            }
        }
    }
    return (0);
}

int check_semicolon(char *line, t_cmd *cmd, int *i)
{
	if (line[*i] == ';')
	{
		if (cmd->quote == 0)
		{
			line[*i] = '\0';
			add_token(cmd);
			add_cmd(cmd);
			return (1);
		}
		else if (line[*i + 1] == ';')
			error_syntax(";;");
	}
	return (0);
}