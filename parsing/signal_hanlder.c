/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_hanlder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:12:05 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/08 03:53:55 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    set_signal(void)
{
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
    signal(SIGTERM, signal_handler);
}

void signal_handler(int signo)
{
    pid_t   pid;
    
    pid = waitpid(-1, NULL, WNOHANG);
        
    // 동작은 똑같이 하는데 ^C는 출력되는게 bash랑 다름
    if (signo == SIGINT)
    {
        if (pid == -1) //자식 프로세스가 없을 때
        {
            printf("\n");
            rl_on_new_line();
            rl_replace_line("", 0);
            rl_redisplay();
            printf(" \b\b"); 
        }
        else
            ft_putchar_fd('\n', 1);
        
    }
    else if (signo == SIGQUIT)
    {
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
    // 이건 구현해야하는지 모르겠음
    // else if (signo == SIGTERM)
    // {
    //     printf("exit\n");
    //     exit(EXIT_SUCCESS);
    // }
}