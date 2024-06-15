/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:39:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 23:42:38 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

char	**find_value(char *key, t_data *data)
{
	t_env	*env;

	env = data->env;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

t_env	*find_env_with_key(t_data *data, char *key)
{
	t_env	*iter;

	iter = data->env;
	while (iter)
	{
		if (!ft_strcmp(iter->key, key))
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

// value가 ':' 기준으로 나뉘어진 문자열임이 자명한
void	add_env_value(t_data *data, char *key, char *value)
{
	t_env	*env;
	char	**new_value;
	int		idx;

	env = find_env_with_key(data, key);
	if (env == NULL)
	{
		new_env(data, key, value);
		return ;
	}
	new_value = malloc((sizeof(char *)) * (value_size(env) + 2));
	if (new_value == NULL)
		exit(1); // todo : 에러 처리 추가
	idx = 0;
	while (env->value[idx])
	{
		new_value[idx] = env->value[idx];
		idx++;
	}
	new_value[idx] = ft_strdup(value);
	new_value[idx + 1] = NULL;
	free(env->value);
	env->value = new_value;
}

void	new_env(t_data *data, char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	new->key = ft_strdup(key);
	new->value = malloc(sizeof(char *) * 2);
	if (new->value == NULL)
		exit(1); // todo : 에러 처리 추가
	new->value[0] = ft_strdup(value);
	new->value[1] = NULL;
	new->next = NULL;
	if (data->env == NULL)
	{
		data->env = new;
		return ;
	}
	new->next = data->env;
	data->env = new;
}
