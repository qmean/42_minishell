/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:33:14 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/29 01:05:40 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

void	execute(t_line *line)
{
	if (line->first_cmd == NULL)
		return ;
	if (line->pipe_flag == 1)
		do_pipe_cmd(line, line->first_cmd);
	else
		do_normal_cmd(line, line->first_cmd);
}
