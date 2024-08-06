/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:55:18 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 01:13:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*make_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->buf = NULL;
	new->quote = '\0';
	new->input_file = -2;
	new->output_file = -2;
	new->tokens = make_token();
	new->first_token = new->tokens;
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
	new->data = NULL;
	new->prev = NULL;
	new->next = NULL;
	new->isspace = 0;
	return (new);
}
