/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:09:01 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 02:13:54 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	valid_exit_status(char *str);

void	ft_exit(t_line *line, t_token *token)
{
	int	idx;

	if (token_size(token) == 0)
		line->exit_flag = 0;
	idx = 0;
	while (token != NULL)
	{
		if (idx != 0)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			line->exit_flag = 1; // todo : fix exit flag
			return ;
		}
		if (!valid_exit_status(token->data))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(token->data, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			line->exit_flag = 2; // todo : fix exit flag
			return ;
		}
		idx++;
		token = token->next;
	}
}

int	valid_exit_status(char *str)
{
	int	idx;

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
