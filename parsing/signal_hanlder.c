/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_hanlder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:12:05 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/10 00:25:23 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    set_signal(void)
{
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, SIG_IGN);
}

void signal_handler(int signo)
{
    pid_t   pid;
    
    pid = waitpid(-1, NULL, WNOHANG);
    sigint_printc_off();
        
    if (signo == SIGINT)
    {
        if (pid == -1) //자식 프로세스가 없을 때
        {
            ft_putchar_fd('\n', 1); // 줄바꿈
            rl_on_new_line(); //커서를 새로운 줄로 이동
            rl_replace_line("", 0); //버퍼를 비움
            rl_redisplay(); //화면에 출력
        }
        else //자식 프로세스가 있을 때
        {
            sigint_printc_on();
            ft_putchar_fd('\n', 1);
        }
    }
}

void    sigint_printc_off(void)
{
    struct termios termios_p;

    // 현재 터미널 속성 가져오기
    tcgetattr(0, &termios_p);

    // ECHO 플래그 비활성화
    termios_p.c_lflag &= ~ECHOCTL;

    // 터미널 속성 설정하기
    tcsetattr(0, TCSANOW, &termios_p);
}

void    sigint_printc_on(void)
{
    struct termios termios_p;

    // 현재 터미널 속성 가져오기
    tcgetattr(0, &termios_p);

    // ECHO 플래그 활성화
    termios_p.c_lflag |= ECHOCTL;

    // 터미널 속성 설정하기
    tcsetattr(0, TCSANOW, &termios_p);
}

void    sig_term_handler(void) // ctrl + D 처리용
{
    ft_putstr_fd("\033[1A", 2); // 현재 커서의 위치를 한칸 위로 올려줌 
	ft_putstr_fd("\033[12C", 2); // 현재 커서의 위치를 12번째칸으로 이동
	ft_putstr_fd("\bexit\n", 2);
}