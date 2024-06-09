/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:30:12 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/10 04:15:11 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	check_and_add_env(t_data *data, char *arg);
int		check_no_value(char *arg);

void do_no_value(t_data *data, char *arg);

char **no_value_split(char *arg);

int	add_env(t_data *data, char *arg)
{
	if (export_check_validated(arg))
		return (1);
	if (check_valid_underbar_char(arg))
		return (0);
	check_and_add_env(data, arg);
	return (0);
}

void	check_and_add_env(t_data *data, char *arg)
{
	if (check_plus(arg))
		do_plus(data, arg);
	else if (check_change(arg))
		do_change(data, arg);
	else if (check_no_value(arg))
		do_no_value(data, arg);
	else
		do_normal(data, arg);
}

void	do_no_value(t_data *data, char *arg)
{
	char	**values;
	char	*key;
	int		idx;

	while (arg[idx] != '=')
		idx++;
	key = ft_substr(arg, 0, idx);
	values = find_value(key, data);
	if (values)
	{
		idx = 0;
		while (values[idx] != NULL)
		{
			free(values[idx]);
			idx++;
		}
		free(values[idx]);
		free(values);
	}
	free(key);
}

int	check_no_value(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx] != '=')
		idx++;
	if (arg[idx + 1] == '\0')
		return (1);
	return (0);
}
