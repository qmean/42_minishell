/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:56:28 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/31 20:07:56 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	ret;

	if (lst == NULL)
		return (0);
	ret = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		ret++;
	}
	return (ret);
}
