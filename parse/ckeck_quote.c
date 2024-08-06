/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:31:32 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 02:50:06 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quote(char *line, t_cmd *cmd, int *i)
{
	if (check_smallquote(line, cmd, i) || check_bigquote(line, cmd, i))
		return (1);
	return (0);
}

int	check_smallquote(char *line, t_cmd *cmd, int *i)
{
	if (line[*i] == '\'')
	{
		if (cmd->quote == 0)
			cmd->quote = '\'';
		else if (cmd->quote == '\'')
			cmd->quote = 0;
		else
			cmd->buf = ft_strjoin_free(cmd->buf, line[*i]);
		*i += 1;
		return (1);
	}
	return (0);
}

int	check_bigquote(char *line, t_cmd *cmd, int *i)
{
	if (line[*i] == '\"')
	{
		if (cmd->quote == 0)
			cmd->quote = '\"';
		else if (cmd->quote == '\"')
			cmd->quote = 0;
		else
			cmd->buf = ft_strjoin_free(cmd->buf, line[*i]);
		*i += 1;
		return (1);
	}
	return (0);
}
