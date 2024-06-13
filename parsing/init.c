/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:57:28 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/14 03:32:59 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    init(t_line *lines)
{
    lines->cmds = make_cmd();
    lines->first_cmd = lines->cmds;
    lines->cmds->tokens = make_token();
    lines->cmds->first_token = lines->cmds->tokens;
}