/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:59:46 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 01:13:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	input_redirection(t_cmd *cmds, t_token *token)
{
	if (cmds->input_file != -2)
		close(cmds->input_file);
	cmds->input_file = open(token->next->data, O_RDONLY);
	if (cmds->input_file < 0)
		return (error_nofile(token->next->data));
	printf("input file: %d %s\n", cmds->input_file, token->next->data);
	return (0);
}

int	input_heredoc_redirection(t_cmd *cmds, t_token *token)
{
	if (cmds->input_file != -2)
		close(cmds->input_file);
	cmds->input_file = 0;
	cmds->heredoc_str = ft_strdup(token->next->data);
	if (cmds->heredoc_str == NULL)
		return (-1);
	printf("input file: %d %s\n", cmds->input_file, token->next->data);
	return (0);
}

int	output_redirection(t_cmd *cmds, t_token *token)
{
	if (cmds->output_file != -2)
		close(cmds->output_file);
	cmds->output_file = \
	open(token->next->data, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmds->output_file < 0)
		return (error_nofile(token->next->data));
	printf("output file1: %d %s\n", cmds->output_file, token->next->data);
	return (0);
}

int	output_append_redirection(t_cmd *cmds, t_token *token)
{
	if (cmds->output_file != -2)
		close(cmds->output_file);
	cmds->output_file = \
	open(token->next->data, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (cmds->output_file < 0)
		return (error_nofile(token->next->data));
	printf("output file2: %d %s\n", cmds->output_file, token->next->data);
	return (0);
}
