/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_hanlder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:12:05 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/06 16:02:51 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_handler(int signo)
{
	pid_t	pid;

	sigint_printc_off();
	pid = waitpid(-1, NULL, WNOHANG);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			ft_putchar_fd('\n', 1);
			rl_on_new_line();
							  // todo : makefile 설정시 추가           rl_replace_line("", 0); //버퍼를 비움
			rl_redisplay();
		}
		else
		{
			sigint_printc_on();
			ft_putchar_fd('\n', 1);
		}
	}
}

void	sigint_printc_off(void)
{
	struct termios	termios_p;

	tcgetattr(0, &termios_p);
	termios_p.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &termios_p);
}

void	sigint_printc_on(void)
{
	struct termios	termios_p;

	tcgetattr(0, &termios_p);
	termios_p.c_lflag |= ECHOCTL;
	tcsetattr(0, TCSANOW, &termios_p);
}

void	sig_term_handler(void)
{
	ft_putstr_fd("\033[1A", 2);
	ft_putstr_fd("\033[11C", 2);
	ft_putstr_fd("exit\n", 2);
}
