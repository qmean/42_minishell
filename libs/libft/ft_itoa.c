/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:14:08 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/05 19:33:59 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cal_len(long long inp);
void	push_num(char *ret, long long inp, int len);

char	*ft_itoa(int n)
{
	char		*ret;
	long long	inp;
	int			len;

	inp = n;
	if (inp < 0)
	{
		inp = -inp;
		len = cal_len(inp) + 1;
		ret = (char *)malloc(sizeof(char) * len);
		if (ret == NULL)
			return (NULL);
		ret[0] = '-';
	}
	else
	{
		len = cal_len(inp);
		ret = (char *)malloc(sizeof(char) * len);
		if (ret == NULL)
			return (NULL);
	}
	push_num(ret, inp, len);
	return (ret);
}

int	cal_len(long long inp)
{
	int	ret;

	ret = 0;
	if (inp == 0)
		return (2);
	while (inp != 0)
	{
		ret++;
		inp = inp / 10;
	}
	return (ret + 1);
}

void	push_num(char *ret, long long inp, int len)
{
	ret[--len] = 0;
	if (inp == 0)
	{
		ret[--len] = '0';
		return ;
	}
	while (inp != 0)
	{
		ret[--len] = inp % 10 + '0';
		inp = inp / 10;
	}
	return ;
}
