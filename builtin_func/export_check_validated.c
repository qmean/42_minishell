/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check_validated.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 02:16:03 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_valid_first_char(char *arg);
int	check_valid_null_char(char *arg);
int	check_valid_special_char(char *arg);

int	export_check_validated(char *arg)
{
	if (check_valid_first_char(arg))
		return (1);
	else if (check_valid_special_char(arg))
		return (1);
	else if (check_valid_null_char(arg))
		return (1);
	else
		return (0);
}

int	check_valid_null_char(char *arg)
{
	if (*arg == '\0')
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	return (0);
}

int	check_valid_underbar_char(char *arg)
{
	if (ft_strcmp(arg, "_") == 0)
		return (1);
	else
		return (0);
}

int	check_valid_special_char(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx] != '\0' && arg[idx] != '=')
	{
		if (!ft_isalnum(arg[idx]) && arg[idx] != '_' && !check_plus(arg))
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		idx++;
	}
	return (0);
}

int	check_valid_first_char(char *arg)
{
	if (ft_isalpha(*arg) || *arg == '_')
		return (0);
	else
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
}
