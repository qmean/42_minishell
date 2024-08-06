/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:38:57 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_cmd(t_line *lines) {
	t_token *token;
	t_cmd *tmp;
	int i;
	int j;

	j = 1;
	tmp = lines->first_cmd;
	printf("============print_cmd==========\n");
	while (tmp) {
		printf("input_file: %d\n", tmp->input_file);
		printf("output_file: %d\n", tmp->output_file);
		token = tmp->first_token;
		i = 1;
		printf("cmd%d \n", j);
		while (token) {
			printf("token%d: %s  pipe: %d redir: %d\n", i, token->data, lines->pipe_flag, token->redir);
			token = token->next;
			i++;
		}
		printf("token%d: NULL\n", i);
		tmp = tmp->next;
		j++;
	}
	printf("cmd%d \n", j);
	printf("NULL\n");
	printf("============print_cmd==========\n");
}