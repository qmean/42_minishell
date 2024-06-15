/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:10 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 23:25:45 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	env(t_data *data)
{
	t_env	*env;

	env = data->env;
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
	int	i;

	ft_putstr_fd(env->key, 1);
	ft_putchar_fd('=', 1);
	i = 0;
	if (env->value[i] != NULL)
	{
		ft_putstr_fd(env->value[i], 1);
		i++;
	}
	while (env->value[i] != NULL)
	{
		ft_putchar_fd(':', 1);
		ft_putstr_fd(env->value[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
