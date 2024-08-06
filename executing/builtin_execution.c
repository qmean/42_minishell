/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:04:46 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/06 19:00:08 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	execute_builtin(t_line *line, t_cmd *cmd, int cmd_def)
{
	if (cmd_def == BCD)
		cd(line, cmd);
	else if (cmd_def == BECHO)
		echo(line, cmd->first_token->next);
	else if (cmd_def == BENV)
		env(line, cmd->first_token->next);
	else if (cmd_def == BEXPORT)
		export(line, cmd->first_token->next);
	else if (cmd_def == BPWD)
		pwd(line);
	else if (cmd_def == BUNSET)
		unset(line, cmd->first_token->next);
	else if (cmd_def == BEXIT)
		ft_exit(line, cmd->first_token->next);
}

int	isbuiltin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->first_token->data, "cd"))
		return (BCD);
	if (!ft_strcmp(cmd->first_token->data, "echo"))
		return (BECHO);
	if (!ft_strcmp(cmd->first_token->data, "env"))
		return (BENV);
	if (!ft_strcmp(cmd->first_token->data, "export"))
		return (BEXPORT);
	if (!ft_strcmp(cmd->first_token->data, "pwd"))
		return (BPWD);
	if (!ft_strcmp(cmd->first_token->data, "unset"))
		return (BUNSET);
	if (!ft_strcmp(cmd->first_token->data, "exit"))
		return (BEXIT);
	return (0);
}
