/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check_and_do.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:30:12 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_and_add_env(t_line *line, char *arg);
int		check_change(char *arg);
int		check_no_value(char *arg);

int	add_env(t_line *line, char *arg)
{
	if (export_check_validated(arg))
		return (1);
	if (check_valid_underbar_char(arg))
		return (0);
	check_and_add_env(line, arg);
	return (0);
}

void	check_and_add_env(t_line *line, char *arg)
{
	if (check_plus(arg))
		do_plus(line, arg);
	else if (check_change(arg))
		do_change(line, arg);
	else if (check_no_value(arg))
		do_no_value(line, arg);
	else
		do_keys(line, arg);
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

int	check_no_value(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx] != '\0')
	{
		if (arg[idx] == '=' && arg[idx + 1] == '\0')
			return (1);
		idx++;
	}
	return (0);
}
