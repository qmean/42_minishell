/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:53:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/22 01:44:20 by jaemikim         ###   ########.fr       */
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
	// printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	// printf("============print_cmd==========\n");
	// printf("===============================\n");
    while (tmp)
    {
        token = tmp->first_token;
        i = 1;
        printf("cmd%d \n", j);
        while (token)
        {
            printf("token%d: %8s dir: %d pipe: %d\n", i, token->data, token->redir, token->pipe_flag);
            token = token->next;
            i++;
        }
        tmp = tmp->next;
        j++;
    }
	// printf("===============================\n");
	// printf("============print_cmd==========\n");
	// printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
}
