/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_executing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:14:10 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/05 01:42:10 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

void	do_heredoc(t_cmd *cmd);

void	do_redirect_cmd(t_line *line, t_cmd *cmd)
{
	if (cmd->input_file == -2 && cmd->output_file == -2)
		return ;
	if (cmd->input_file > 0)
		dup2(cmd->input_file, STDIN_FILENO);
	if (cmd->output_file >= 0)
		dup2(cmd->output_file, STDOUT_FILENO);
	if (cmd->input_file == 0)
		do_heredoc(cmd);
}

void	do_heredoc(t_cmd *cmd)
{
	char	*heredoc_line;

	cmd->input_file = open("/tmp/heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (cmd->input_file == -1)
		print_error(cmd->first_token->data, NULL, "open error");
	while (1)
	{
		heredoc_line = readline("> ");
		if (!ft_strcmp(heredoc_line, cmd->heredoc_str))
		{
			free(heredoc_line);
			break ;
		}
		write(cmd->input_file, heredoc_line, ft_strlen(heredoc_line));
		write(cmd->input_file, "\n", 1);
		free(heredoc_line);
	}
	close(cmd->input_file);
	cmd->input_file = open("/tmp/heredoc", O_RDONLY);
	if (cmd->input_file == -1)
		print_error(cmd->first_token->data, NULL, "open error");
	dup2(cmd->input_file, STDIN_FILENO);
}

void	restore_stdio(t_cmd *cmd, int stdout, int stdin)
{
	if (cmd->output_file != -2)
		close(cmd->output_file);
	if (cmd->input_file != -2)
		close(cmd->input_file);
	dup2(stdout, STDOUT_FILENO);
	dup2(stdin, STDIN_FILENO);
	close(stdout);
	close(stdin);
}
