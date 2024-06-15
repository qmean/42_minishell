/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_change_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 03:42:47 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 22:27:33 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	do_change(t_data *data, char *arg)
{
	char	**splited;
	char	*key;
	char	*value;
	char	**splited_value;
	int		idx;

	splited = change_split(arg);
	key = splited[0];
	value = splited[1];
	splited_value = value_split(value);
	delete_values(find_env_with_key(data, key));
	idx = 0;
	while (splited_value[idx])
	{
		add_env_value(data, key, splited_value[idx]);
		idx++;
	}
	free_values(splited_value);
	free(key);
	free(value);
	free(splited);
}

char	**change_split(char *arg)
{
	char	**result;
	int		idx;

	result = (char **)malloc(sizeof(char *) * 2);
	idx = 0;
	while (arg[idx] != '=')
		idx++;
	result[0] = ft_substr(arg, 0, idx);
	result[1] = ft_strdup(arg + idx + 1);
	return (result);
}

void	change_env_value(t_data *data, char *key, char *value)
{
	char	**old;

	old = find_value(key, data);
	if (old)
	{
		free(*old);
		*old = ft_strdup(value);
	}
	else
	{
		old = (char **)malloc(sizeof(char *) * 2);
		old[0] = ft_strdup(value);
		old[1] = NULL;
		add_env_node(data, key, old);
	}
}

int	check_change(char *arg)
{
	int	idx;

	if (ft_strlen(arg) <= 1)
		return (0);
	idx = 0;
	while (arg[idx + 1] != '\0')
	{
		if (arg[idx] == '=')
			return (1);
		idx++;
	}
	return (0);
}
