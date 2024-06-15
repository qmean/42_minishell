/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:36:34 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 22:35:44 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	export(t_data *data, char **args)
{
	int	exit_flag;
	int	idx;

	exit_flag = 0;
	if (*args == NULL)
		export_with_no_args(data);
	idx = 0;
	while (args[idx])
	{
		if (add_env(data, args[idx]) == 1)
			exit_flag = 1;
		idx++;
	}
	return (exit_flag);
}
