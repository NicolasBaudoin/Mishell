/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:12:39 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/04 17:15:15 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*curr;

	if (!lst || !new_lst)
		return ;
	curr = *lst;
	if (!curr)
	{
		*lst = new_lst;
		return ;
	}
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new_lst;
}
