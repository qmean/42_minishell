/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:31:32 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/12 04:16:00 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_quote(char *line, t_cmd *cmd, int *i)
{
    if (check_smallquote(line, cmd, i) || check_bigquote(line, cmd, i))
        return (1);
    return 0;
}

int check_smallquote(char *line, t_cmd *cmd, int *i)
{
    if (line[*i] == '\'')
    {
        if (cmd->quote == 0)
            cmd->quote = '\'';
        else if (cmd->quote == '\'')
        {
            cmd->quote = 0;
            add_token(cmd);
        }
        *i += 1;
        return (1);
    }
    return (0);
}

int check_bigquote(char *line, t_cmd *cmd, int *i)
{
    if (line[*i] == '\"')
    {
        if (cmd->quote == 0)
            cmd->quote = '\"';
        else if (cmd->quote == '\"')
        {
            cmd->quote = 0;
            add_token(cmd);
        }
        *i += 1;
        return (1);
    }
    return (0);
}