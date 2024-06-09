/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:41:50 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/09 23:25:51 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	print_env_with_sort(t_env *env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->key, 1);
		print_export_values(env->value);
		env = env->next;
	}
}

void	print_export_values(char **value)
{
	int	i;

	if (value != NULL)
	{
		ft_putstr_fd("=\"", 1);
		i = 0;
		while (value[i] != NULL)
		{
			ft_putstr_fd(value[i], 1);
			if (value[i + 1] != NULL)
				ft_putstr_fd(":", 1);
			i++;
		}
		ft_putstr_fd("\"\n", 1);
	}
	else
		ft_putstr_fd("\n", 1);
}
