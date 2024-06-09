/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:36:34 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/10 03:40:37 by kyuminkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	export(t_data *data, char **args)
{
	int	exit_flag;

	exit_flag = 0;
	if (*args == NULL)
		export_with_no_args(data);
	while (*args)
	{
		if (add_env(data, *args) == 1)
			exit_flag = 1;
		args++;
	}
	exit(exit_flag);
}
