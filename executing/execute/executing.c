/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:33:14 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/05 01:42:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

void	execute(t_line *line)
{
	int	stdin_copy;
	int	stdout_copy;

	stdin_copy = dup(STDIN_FILENO);
	stdout_copy = dup(STDOUT_FILENO);
	if (line->first_cmd == NULL)
		return ;
	if (line->pipe_flag == 1)
	{
		do_pipe_cmd(line, line->first_cmd, NULL);
	}
	else
	{
		do_normal_cmd(line, line->first_cmd);
		restore_stdio(line->first_cmd, stdout_copy, stdin_copy);
	}
}
