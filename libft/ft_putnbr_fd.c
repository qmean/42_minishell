/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:51:41 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 17:37:33 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printnum(long long n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	printnum((long long)n, fd);
	return ;
}

void	printnum(long long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		printnum(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}
