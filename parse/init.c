/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:57:28 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 04:03:33 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init(t_line *lines)
{
	lines->cmds = make_cmd();
	lines->first_cmd = lines->cmds;
	lines->cmds->first_token = lines->cmds->tokens;
	lines->pipe_flag = 0;
}
