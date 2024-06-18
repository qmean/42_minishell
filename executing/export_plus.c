/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 02:47:28 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/16 01:52:54 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int count_values_by_string(char *values);

void add_end_value(t_data *data, char *key, char *str);

void	do_plus(t_data *data, char *arg)
{
	char	**splited;
	char	*key;
	char	*value;
	char	**splited_value;
	int		idx;

	splited = plus_split(arg);
	key = splited[0];
	value = splited[1];
	splited_value = value_split(value);
	idx = 0;
	add_end_value(data, key, splited_value[idx++]);
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

void	add_env_node(t_data *data, char *key, char **values)
{
	t_env	*new;
	t_env	*env;

	new = (t_env *) malloc(sizeof(t_env));
	if (new == NULL)
		exit(1); // todo : 에러 처리 추가
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

	ret = (char **) malloc(sizeof(char *) * 2);
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

char	**value_split(char *str)
{
	char	**ret;
	int		idx;
	int		cnt;
	int		len;

	ret = (char **) malloc(sizeof(char *) * (count_values_by_string(str) + 1));
	idx = 0;
	cnt = 0;
	while (str[idx] != '\0')
	{
		len = 0;
		while (str[idx + len] != ':' && str[idx + len] != '\0')
			len++;
		if (len == 0)
			ret[cnt] = ft_strdup("");
		else
			ret[cnt] = ft_substr(str, idx, len);
		idx += len + 1;
		cnt++;
	}
	if (str[idx - 1] == ':')
		ret[cnt++] = ft_strdup("");
	ret[cnt] = NULL;
	return (ret);
}

int	count_values_by_string(char *values)
{
	int	cnt;
	int	idx;

	cnt = 1;
	idx = 0;
	while (values[idx])
	{
		if (values[idx] == ':')
			cnt++;
		idx++;
	}
	return (cnt);
}
