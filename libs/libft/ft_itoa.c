/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:14:08 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/16 02:29:49 by jaemikim         ###   ########.fr       */
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
	ret[len - 1] = '\0';
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
