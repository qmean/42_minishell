#include "parsing.h"

void print_cmd(t_line *lines)
{
	t_token *token;
	t_cmd *tmp;
	int i;
	int j;

	j = 1;
	tmp = lines->first_cmd;
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
			printf("token%d: %s  pipe: %d redir: %d\n", i, token->data, lines->pipe_flag, token->redir);
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