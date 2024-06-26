/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:55:18 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/16 01:57:59 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	*make_cmd(void)
{
    t_cmd	*new;

    new = (t_cmd *)malloc(sizeof(t_cmd));
    if (!new)
        return (NULL);
    new->buf = NULL;
    new->pipe_flag = 0;
    new->redirect = 0;
    new->quote = '\0';
    new->tokens = NULL;
    new->env = NULL;
    new->next = NULL;
    return (new);
}

t_token	*make_token(void)
{
    t_token	*new;

    new = (t_token *)malloc(sizeof(t_token));
    if (!new)
        return (NULL);
    new->redir = '\0';
    new->redir_args[0] = NULL;
    new->redir_args[1] = NULL;
    new->data = NULL;
    new->next = NULL;
    new->isspace = 0;
    return (new);
}