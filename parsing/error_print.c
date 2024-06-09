/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 04:23:46 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/10 05:02:24 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_invalid_quote(void)
{
    ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
    exit(EXIT_FAILURE);
}

void    error_syntax(char c)
{
    ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
    if (c == '\0')
        ft_putstr_fd("newline'\n", 2);
    else
        ft_putchar_fd(c, 2);
    ft_putstr_fd("'\n", 2);
    exit(EXIT_FAILURE);
}