/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:10 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/06 16:57:14 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	env(t_data *data)
{
	t_env	*env;
	int		i;

	env = data->env;
	while (env != NULL)
	{
		ft_putstr_fd(env->key, 1);
		ft_putchar_fd('=', 1);
		i = 0;
		if (env->value[i] != NULL)
		{
			ft_putstr_fd(env->value[i], 1);
			i++;
		}
		while (env->value[i] != NULL)
		{
			ft_putchar_fd(':', 1);
			ft_putstr_fd(env->value[i], 1);
			i++;
		}
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
}
