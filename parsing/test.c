#include "parsing.h"

void    print_cmd(t_cmd *cmd)
{
    t_token *token;
    t_cmd *tmp;

    tmp = cmd;
    while (tmp)
    {
        token = tmp->first_token;
        while (token)
        {
            printf("token: %s \n", token->data);
            token = token->next;
        }
        tmp = tmp->next;
    }
}
