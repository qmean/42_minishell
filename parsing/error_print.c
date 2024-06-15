/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 04:23:46 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/14 04:07:08 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_invalid_quote(void)
{
    ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
    exit(EXIT_FAILURE);
}

void    error_syntax(char *c)
{
    ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
    if (c == NULL)
        ft_putstr_fd("newline", 2);
    else
        ft_putstr_fd(c, 2);
    ft_putstr_fd("'\n", 2);
    exit(EXIT_FAILURE);
}