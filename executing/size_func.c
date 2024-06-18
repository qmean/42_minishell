/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:58:53 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 03:40:52 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	cmd_size(t_cmd *cmd)
{
	int		ret;

	ret = 0;
	while (cmd)
	{
		ret++;
		cmd = cmd->next;
	}
	return (ret);
}

int	env_size(t_line *line)
{
	t_env	*env;
	int		ret;

	ret = 0;
	env = line->env;
	while (env)
	{
		ret++;
		env = env->next;
	}
	return (ret);
}

int	token_size(t_token *token)
{
	int		ret;

	ret = 0;
	if (token == NULL)
		return (0);
	while (token->data != NULL)
	{
		ret++;
		token = token->next;
	}
	return (ret);
}
