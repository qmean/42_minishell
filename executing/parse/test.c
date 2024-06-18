/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:53:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 02:34:33 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    print_cmd(t_cmd *cmd)
{
    t_token *token;
    t_cmd *tmp;
    int i;
    int j;

    j = 1;
    tmp = cmd;
    while (tmp)
    {
        token = tmp->first_token;
        i = 1;
        printf("cmd%d \n", j);
        while (token)
        {
            printf("token%d: %s \n", i, token->data);
            token = token->next;
            i++;
        }
        tmp = tmp->next;
        j++;
    }
}
