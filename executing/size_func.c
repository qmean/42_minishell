/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:58:53 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/12 12:01:02 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	cmd_size(char **cmdlist)
{
	int	i;

	i = 0;
	while (cmdlist[i] != NULL)
		i++;
	return (i);
}

int	env_size(t_data data)
{
	t_env	*env;
	int		ret;

	ret = 0;
	env = data.env;
	while (env)
	{
		ret++;
		env = env->next;
	}
	return (ret);
}

int	value_size(t_env *env)
{
	char	**value;
	int		idx;

	idx = 0;
	value = env->value;
	while (value[idx])
	{
		idx++;
	}
	return (idx);
}
