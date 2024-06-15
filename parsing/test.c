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

void    set_env(t_env *env)
{
    t_env *tmp;
    int i;

    i = 1;
    (env)->key = ft_strdup("key");
    env->value = malloc(sizeof(char *) * 2);
    env->value[0] = ft_strcat(ft_strdup("value "), ft_itoa(i));
    (env)->next = NULL;

    tmp = env;
    for (i = 2; i <= 10; i++)
    {
        tmp->next = (t_env *)malloc(sizeof(t_env));
        tmp = tmp->next;
        tmp->key = ft_strdup(ft_itoa(i));
        tmp->value = malloc(sizeof(char *) * 2);
        tmp->value[0] = ft_strcat(ft_strdup("value "), ft_itoa(i));
        tmp->next = NULL;
    }
}