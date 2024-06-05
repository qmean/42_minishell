/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:51:16 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 17:15:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	int		cnt;

	ret = (char *)malloc(count * size);
	if (ret == NULL)
		return (NULL);
	cnt = 0;
	while (cnt < (int)(count * size))
	{
		ret[cnt] = 0;
		cnt++;
	}
	return (ret);
}
