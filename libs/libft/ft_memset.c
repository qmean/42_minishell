/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:22:55 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/31 19:49:26 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;
	unsigned char	inp;
	int				idx;

	ret = b;
	inp = c;
	idx = 0;
	while (len--)
	{
		ret[idx++] = inp;
	}
	return (ret);
}
