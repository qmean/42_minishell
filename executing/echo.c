/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:53:23 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 03:52:13 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	print_default(t_token *token);
int		check_n_option(const char *str);
void	print_n_option(t_token *token);

void	echo(t_line *line, t_token *token)
{
	int	n_option;

	if (token_size(token) == 0)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	n_option = 0;
	while (token != NULL)
	{
		if (check_n_option(token->data))
			n_option = 1;
		else
			break ;
		token = token->next;
	}
	if (n_option)
	{
		print_n_option(token);
		return ;
	}
	print_default(token);
	line->exit_flag = 0;
}

void	print_default(t_token *token)
{
	while (token != NULL)
	{
		ft_putstr_fd(token->data, 1);
		token = token->next;
		if (token != NULL)
			ft_putstr_fd(" ", 1);
	}
	ft_putstr_fd("\n", 1);
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

void	print_n_option(t_token *token)
{
	while (token != NULL)
	{
		ft_putstr_fd(token->data, 1);
		token = token->next;
		if (token != NULL)
			ft_putstr_fd(" ", 1);
	}
}
