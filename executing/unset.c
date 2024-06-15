/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:17:56 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/18 20:20:08 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	delete_env(t_data *data, t_env *env);

void	unset(t_data *data, char **args)
{
	int		i;
	t_env	*env;

	i = 0;
	while (args[i])
	{
		env = find_env_with_key(data, args[i]);
		if (env)
			delete_env(data, env);
		i++;
	}
}

void	delete_env(t_data *data, t_env *env)
{
	t_env	*iter;

	iter = data->env;
	if (iter == env)
	{
		data->env = iter->next;
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

