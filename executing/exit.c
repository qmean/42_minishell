/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:09:01 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/18 22:29:07 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int valid_exit_status(char *str);

void	ft_exit(t_data *data, char **args)
{
	int	idx;

	if (cmd_size(args) == 0)
	{
		exit(0); // todo : exit_status 와 메모리 해제
	}
	idx = 0;
	while(args[idx] != '\0')
	{
		if (idx != 0)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			exit(1); // todo : exit_status 와 메모리 해제
		}
		if (!valid_exit_status(args[idx]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(args, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255); // todo : exit_status 와 메모리 해제
		}
		idx++;
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
}

//숫자로만 된 str이 long long 범위 내에 있는지 알려주는 함수



