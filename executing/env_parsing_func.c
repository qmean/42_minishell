/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:39:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/06 18:22:55 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

// todo : strcmp -> ft_strcmp
char	**find_value(char *key, t_data *data)
{
	t_env	*env;

	env = data->env;
	while (env)
	{
		if (!strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
