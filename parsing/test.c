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
