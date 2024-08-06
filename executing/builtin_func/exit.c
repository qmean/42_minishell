/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:09:01 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/06 19:05:50 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	valid_exit_status(char *str);

void	ft_exit(t_line *line, t_token *token)
{
	if (token_size(token) == 0)
		exit(0);
	else if (!valid_exit_status(token->data))
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(token->data, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(2);
	}
	else if (token_size(token) > 1)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		line->exit_flag = 1;
		return ;
	}
	else
		exit(ft_atoi(token->data));
}

int	valid_exit_status(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	if (ft_strlen(str) > 10)
		return (0);
	else
		return (1);
}
