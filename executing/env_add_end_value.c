/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add_end_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:43:24 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 23:49:26 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	add_env_value_null(const char *str, t_env *env, char **values);
void	add_env_value_not_null(const char *str, char **values);
void	add_env_value_env_null(t_data *data, char *key, const char *str);

void	add_end_value(t_data *data, char *key, char *str)
{
	t_env	*env;

	env = find_env_with_key(data, key);
	if (env == NULL)
	{
		add_env_value_env_null(data, key, str);
		return ;
	}
	if (env->value == NULL)
	{
		add_env_value_null(str, env, env->value);
		return ;
	}
	add_env_value_not_null(str, env->value);
}

void	add_env_value_env_null(t_data *data, char *key, const char *str)
{
	char	**values;

	values = (char **) malloc(sizeof(char *) * 2);
	if (values == NULL)
		exit(1); // todo : 에러 처리 추가
	values[0] = ft_strdup(str);
	values[1] = NULL;
	add_env_node(data, key, values);
}

void	add_env_value_not_null(const char *str, char **values)
{
	char	*tmp;
	int		idx;

	idx = 0;
	while (values[idx])
		idx++;
	if (idx == 0)
	{
		values[idx] = ft_strdup(str);
		return ;
	}
	tmp = values[idx - 1];
	if (tmp != NULL)
		values[idx - 1] = ft_strjoin(tmp, str);
	free(tmp);
}

void	add_env_value_null(const char *str, t_env *env, char **values)
{
	values = (char **) malloc(sizeof(char *) * 2);
	if (values == NULL)
		exit(1); // todo : 에러 처리 추가
	values[0] = ft_strdup(str);
	values[1] = NULL;
	env->value = values;
}
