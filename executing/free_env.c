/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:32:13 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 23:16:06 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->key);
		free_values(tmp->value);
		free(tmp);
	}
}

void	free_values(char **values)
{
	int	i;

	i = 0;
	if (values == NULL)
		return ;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}

void	delete_values(t_env *env)
{
	if (env == NULL)
		return ;
	free_values(env->value);
	env->value = malloc(sizeof(char *));
	if (env->value == NULL)
		exit(1); // todo : 에러 처리 추가
	env->value[0] = NULL;
}
