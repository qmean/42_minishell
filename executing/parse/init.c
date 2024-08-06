/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:57:28 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/06 19:07:55 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    init(t_line *lines)
{
    lines->cmds = make_cmd();
    lines->first_cmd = lines->cmds;
    lines->cmds->tokens = make_token();
    lines->cmds->first_token = lines->cmds->tokens;
    lines->pipe_flag = 0;
}