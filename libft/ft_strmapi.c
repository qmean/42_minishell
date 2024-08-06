/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:43:56 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/29 12:17:59 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		idx;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (ret == NULL)
		return (NULL);
	idx = 0;
	while (*s != 0)
	{
		ret[idx] = f(idx, *s);
		s++;
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}
