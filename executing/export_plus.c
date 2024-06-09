/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 02:47:28 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/10 03:38:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	do_plus(t_data *data, char *arg)
{
	char	**splited;
	char	*key;
	char	*value;

	splited = plus_split(arg);
	key = splited[0];
	value = splited[1];
	add_env_value(data, key, value);
	free(splited[0]);
	free(splited[1]);
	free(splited);
}

void	add_env_value(t_data *data, char *key, char *value)
{
	char	**values;
	char	*new;
	char	*old;

	values = find_value(key, data);
	if (values)
	{
		while (*values)
			values++;
		values--;
		old = *values;
		new = ft_strjoin(old, value);
		free(old);
		*values = new;
	}
	else
	{
		values = (char **) malloc(sizeof(char *) * 2);
		values[0] = ft_strdup(value);
		values[1] = NULL;
		add_env_node(data, key, values);
	}
}

void	add_env_node(t_data *data, char *key, char **values)
{
	t_env	*new;
	t_env	*env;

	new = (t_env *)malloc(sizeof(t_env));
	new->key = ft_strdup(key);
	new->value = values;
	new->next = NULL;
	if (data->env == NULL)
	{
		data->env = new;
		return ;
	}
	env = data->env;
	data->env = new;
	new->next = env;
}

char	**plus_split(char *arg)
{
	char	**ret;
	int		idx;

	ret = (char **)malloc(sizeof(char *) * 2);
	idx = 0;
	while (arg[idx] != '+' || arg[idx + 1] != '=')
		idx++;
	ret[0] = ft_substr(arg, 0, idx);
	ret[1] = ft_strdup(arg + idx + 2);
	return (ret);
}

int	check_plus(char *arg)
{
	int	idx;

	if (ft_strlen(arg) <= 1)
		return (0);
	idx = 0;
	while (arg[idx + 1] != '\0')
	{
		if (arg[idx] == '+' && arg[idx + 1] == '=')
			return (1);
		idx++;
	}
	return (0);
}