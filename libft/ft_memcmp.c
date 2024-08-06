/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:09:56 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 17:34:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*inp1;
	unsigned char	*inp2;
	int				cmp;

	cmp = (int)n;
	inp1 = (unsigned char *)s1;
	inp2 = (unsigned char *)s2;
	while (cmp--)
	{
		if (*inp1 != *inp2)
			break ;
		inp1++;
		inp2++;
	}
	if (cmp == -1)
		return (0);
	else if (*inp1 != *inp2)
		return (*inp1 - *inp2);
	return (0);
}
