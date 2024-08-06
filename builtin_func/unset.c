/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:17:56 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 02:19:16 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delete_env(t_line *line, t_env *env);
int		check_unset(char *arg);

void	unset(t_line *line, t_token *token)
{
	line->exit_flag = 0;
	while (token)
	{
		if (check_unset(token->data) == 0)
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(token->data, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			line->exit_flag = 1;
			return ;
		}
		delete_env(line, find_env_with_key(line, token->data));
		token = token->next;
	}
}

int	check_unset(char *arg)
{
	if (!ft_isalpha(*arg) && *arg != '_')
		return (0);
	return (1);
}

void	delete_env(t_line *line, t_env *env)
{
	t_env	*iter;

	iter = line->env;
	if (iter == env)
	{
		line->env = iter->next;
		free(env->key);
		free(env->value);
		free(env);
		return ;
	}
	while (iter->next)
	{
		if (iter->next == env)
		{
			iter->next = env->next;
			free(env->key);
			free(env->value);
			free(env);
			return ;
		}
		iter = iter->next;
	}
}
