/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_copy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:16:07 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 23:15:32 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

t_env	*copy_env(t_env *env)
{
	t_env	*ret;
	t_env	*new_env_head;

	ret = (t_env *)malloc(sizeof(t_env));
	if (ret == NULL)
		return (NULL);
	new_env_head = ret;
	while (env)
	{
		ret->key = ft_strdup(env->key);
		ret->value = copy_value(env->value);
		if (env->next != NULL)
		{
			ret->next = (t_env *)malloc(sizeof(t_env));
			if (ret->next == NULL)
				return (NULL);
			ret = ret->next;
		}
		env = env->next;
	}
	ret->next = NULL;
	return (new_env_head);
}

char	**copy_value(char **value)
{
	char	**ret;
	int		i;

	if (value == NULL)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (value_len(value) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (value[i])
	{
		ret[i] = ft_strdup(value[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

size_t	value_len(char **value)
{
	size_t	len;

	len = 0;
	while (*value)
	{
		len++;
		value++;
	}
	return (len);
}
