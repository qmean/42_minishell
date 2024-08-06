/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_no_args_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:19:37 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:32:47 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*env_dup(char *key, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		exit(1);
	if (key != NULL)
	{
		env->key = ft_strdup(key);
		if (env->key == NULL)
			exit(1);
	}
	else
		env->key = NULL;
	if (value != NULL)
	{
		env->value = ft_strdup(value);
		if (env->value == NULL)
			exit(1);
	}
	else
		env->value = NULL;
	return (env);
}
