/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:11:10 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/24 21:23:15 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count_size;

	count_size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count_size++;
	}
	return (count_size);
}
