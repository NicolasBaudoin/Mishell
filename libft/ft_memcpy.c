/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:09:36 by nbaudoin          #+#    #+#             */
/*   Updated: 2025/10/25 15:49:53 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*array_dest;
	unsigned char	*array_src;

	if (dest == NULL && src == NULL )
		return (NULL);
	i = 0;
	array_dest = (unsigned char *)dest;
	array_src = (unsigned char *)src;
	while (i < n)
	{
		array_dest[i] = array_src[i];
		i++;
	}
	return ((void *)array_dest);
}
