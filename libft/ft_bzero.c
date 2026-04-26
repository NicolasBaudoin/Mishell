/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:59:43 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/17 11:00:42 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*array;
	size_t			i;

	array = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		array[i] = '\0';
		i++;
	}
}
