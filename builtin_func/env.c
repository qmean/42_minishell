/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:10 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_print(t_env *env);

void	env(t_line *line, t_token *token)
{
	t_env	*env;

	if (token != NULL)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(token->data, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		line->exit_flag = 127;
		return ;
	}
	env = line->env;
	while (env != NULL)
	{
		if (env->value == NULL)
		{
			env = env->next;
			continue ;
		}
		env_print(env);
		env = env->next;
	}
}

void	env_print(t_env *env)
{
	ft_putstr_fd(env->key, 1);
	ft_putchar_fd('=', 1);
	ft_putstr_fd(env->value, 1);
	ft_putchar_fd('\n', 1);
}
