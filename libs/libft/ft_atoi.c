/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:49 by kyumkim           #+#    #+#             */
/*   Updated: 2023/11/07 15:36:51 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	inp;
	int			neg;

	inp = 0;
	neg = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		inp *= 10;
		inp += *str - '0';
		str++;
	}
	return ((int)inp * neg);
}
