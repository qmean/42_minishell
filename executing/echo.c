/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:53:23 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/18 22:06:15 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int		check_n_option(const char *str);
void	print_n_option(char **args);
void	print_default(char **args);

void	echo(char **args)
{
	int	n_option;
	int	idx;

	if (cmd_size(args) == 0)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	n_option = 0;
	idx = 0;
	while (args[idx] != NULL)
	{
		if (check_n_option(args[idx]))
			n_option = 1;
		else
			break ;
		idx++;
	}
	if (n_option)
	{
		print_n_option(args + idx);
		return ;
	}
	print_default(args);
}

void	print_default(char **args)
{
	while (*args != NULL)
	{
		ft_putstr_fd(*args, 1);
		args++;
		if (*args != NULL)
			ft_putstr_fd(" ", 1);
	}
	ft_putstr_fd("\n", 1);
}

void	print_n_option(char **args)
{
	while (*args != NULL)
	{
		ft_putstr_fd(*args, 1);
		args++;
		if (*args != NULL)
			ft_putstr_fd(" ", 1);
	}
}

int	check_n_option(const char *str)
{
	int	idx;

	if (str[0] != '-')
		return (0);
	idx = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] != 'n')
			return (0);
		idx++;
	}
	return (1);
}
