/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paring_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:17:21 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/10 00:21:04 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    iswhitespace(char *c)
{
    while (*c != '\0')
    { 
        if ((*c == ' ' || *c == '\t' || *c == '\n' || *c == '\v' || *c == '\f' || *c == '\r') == 0)
            return (0);
        c++;
    }
    return (1);

}