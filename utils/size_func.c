/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:58:53 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:51 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	env_size(t_env *start)
{
	int		ret;

	ret = 0;
	while (start)
	{
		ret++;
		start = start->next;
	}
	return (ret);
}

int	token_size(t_token *token)
{
	int		ret;

	ret = 0;
	while (token != NULL)
	{
		ret++;
		token = token->next;
	}
	return (ret);
}
