/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_change_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 03:42:47 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/10 03:45:52 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	do_change(t_data *data, char *arg)
{
	char	**splited;
	char	*key;
	char	*value;

	splited = change_split(arg);
	key = splited[0];
	value = splited[1];
	change_env_value(data, key, value);
	free(splited[0]);
	free(splited[1]);
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
