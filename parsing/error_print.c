/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 04:23:46 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/15 23:26:18 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	error_invalid_quote(void)
{
    ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
    return (0);
}

int    error_syntax(char *c)
{
    ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
    if (c == NULL)
        ft_putstr_fd("newline", 2);
    else
        ft_putstr_fd(c, 2);
    ft_putstr_fd("'\n", 2);
    return (0);
}