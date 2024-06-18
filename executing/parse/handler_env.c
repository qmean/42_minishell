/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:05:42 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/19 04:03:37 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_env(char *line, t_line *lines, int *i)
{
    char    *key;
    
    key = ft_strdup("");
    if (line[*i] == '$')
    {
        if ((lines->cmds->quote == 0) || (lines->cmds->quote == '\"'))
        {
            *i += 1;
            if (line[*i] == '$')
            {
                lines->cmds->buf = ft_strcat(lines->cmds->buf, "52342");
                *i += 1;
            }
            else if (line[*i] == '?')
            {
                lines->cmds->buf = ft_strcat(lines->cmds->buf, ft_itoa(lines->exit_flag));
                *i += 1;
            }
            else if (ft_isalnum(line[*i]) || line[*i] == '_')
            {
                while (ft_isalnum(line[*i]) || line[*i] == '_')
                {
                    key = ft_strjoin_free(key, line[*i]);
                    *i += 1;
                }
                get_env_value(key, lines);
            }
            else
            {
                lines->cmds->buf = ft_strcat(lines->cmds->buf, "$");
                return (0);
            }
            
            return (1);
        }
    }
    return (0);
}

void    get_env_value(char *key, t_line *line)
{
    t_env   *env;
    int     is_env;

    is_env = 0;
    env = line->env;
    while (env)
    {
        if (ft_strcmp_par(env->key, key) == 0)
        {
            if (line->env->value != NULL)
            {
				line->cmds->buf = ft_strcat(line->cmds->buf, env->value);
                is_env = 1;
            }
        }
        env = env->next;
    }
    if (is_env == 0)
        line->cmds->buf = ft_strjoin_free(line->cmds->buf, '\0');
}