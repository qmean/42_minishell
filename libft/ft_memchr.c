/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:05:21 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/31 20:07:59 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*inp;

	inp = (unsigned char *)s;
	while (n--)
	{
		if (*inp == (unsigned char)c)
		{
			return (inp);
		}
		inp++;
	}
	return (0);
}
