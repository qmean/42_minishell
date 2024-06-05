/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:22:22 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/30 00:39:54 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	cdst = (char *)dst;
	csrc = (char *)src;
	while (n--)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
	}
	return (dst);
}
